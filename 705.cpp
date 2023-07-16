#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <utility>

#define IDN pair<int, int>
#define NO_IDN IDN(-1, -1)
#define PAIR_IDN pair<IDN, IDN>

#define ROWS 2 * h - 1

#define CHANGE_STATE nodes[id.first][id.second].state =

using namespace std;

struct node
{
  IDN id = IDN(-1, -1);
  IDN f = NO_IDN;
  IDN s = NO_IDN;
  string state = "none";
};

PAIR_IDN get_neighs_even(char left_border, char right_border, int row, int col)
{
  if(left_border == '\\' && right_border == '/')
    return PAIR_IDN(IDN(row - 1, col), IDN(row - 1, col + 1));
  else if(left_border == '/' && right_border == '/')
    return PAIR_IDN(IDN(row + 1, col), IDN(row - 1, col + 1));
  else if(left_border == '\\' && right_border == '\\')
    return PAIR_IDN(IDN(row - 1, col), IDN(row + 1, col + 1));
  else if(left_border == '/' && right_border == '\\')
    return PAIR_IDN(IDN(row + 1, col), IDN(row + 1, col + 1));
}

PAIR_IDN get_neighs_odd(char left_border, char right_border, int row, int col)
{
  if(left_border == '\\' && right_border == '\\')
    return PAIR_IDN(IDN(row - 1, col - 1), IDN(row + 1, col));
  else if(left_border == '/' && right_border == '/')
    return PAIR_IDN(IDN(row + 1, col - 1), IDN(row - 1, col));
  else if(left_border == '\\' && right_border == '/')
    return PAIR_IDN(IDN(row - 1, col - 1), IDN(row + 1, col - 1));
  else if(left_border == '/' && right_border == '\\')
    return PAIR_IDN(IDN(row - 1, col), IDN(row + 1, col));
}

int search(IDN id, vector<vector<struct node>>& nodes, int w, int h)
{
  int cols = w;
  if(id.first < 0 || id.second < 0 ||  id.first >= ROWS || id.second >= cols) return -1;
  struct node n = nodes[id.first][id.second];
  if(n.state != "none") return 0;

  CHANGE_STATE "in";

  int resultf = search(n.f, nodes, w, h);
  int results = search(n.s, nodes, w, h);

  CHANGE_STATE "done";

  if(resultf < 0 || results < 0) return -1;
  return resultf + results + 1;
}


void proccess(vector<string> borders, int w, int h, int maze)
{
  vector<vector<struct node>> nodes(ROWS, vector<struct node>(w));

  for(int i = 0; i < ROWS; i++)
  {
    bool e = false;
    int max = w;
    if(i % 2 == 0) { max--; e = true; };
    for(int j = 0; j < max; j++)
    {
      struct node n;
      n.id.first = i;
      n.id.second = j;

      int row = i / 2;
      int col = j;

      PAIR_IDN neighs;

      if(e) neighs = get_neighs_even(borders[row][col], borders[row][col + 1], i, j);
      else neighs = get_neighs_odd(borders[row][col], borders[row + 1][col], i, j);

      n.f = neighs.first;
      n.s = neighs.second;

      nodes[i][j] = n;
    }
  }

  int biggest_result = 0;
  int count = 0;
  for(vector<struct node> vn : nodes)
  {
    for(struct node n : vn)
    {
      int actual = search(n.id, nodes, w, h);
      if(actual > biggest_result)
      {
        biggest_result = actual;
      }
      if(actual > 0)
      {
        count++;
      }
    }
  }

  cout << "Maze #" << maze << ":" << endl;
  if(count > 0) cout << count << " Cycles; the longest has length " << biggest_result << ".";
  else cout << "There are no cycles.";
  cout << endl << endl;
}

int main(int argc, char** argv)
{
  int maze = 0;
  while(1)
  {
    int w, h;
    scanf("%d %d\n", &w, &h);
    if(w == 0 && h == 0) break;

    vector<string> borders;
    for(int i = 0; i < h; i++)
    {
      string row;
      getline(cin, row);
      borders.push_back(row);
    }

    proccess(borders, w, h, ++maze);
  }

  return 0;
}
