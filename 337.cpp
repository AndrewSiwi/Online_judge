#include <stdio.h>
#include <iostream>
#include <vector>
#include <utility>
#include <string>

enum Mode { insert, overwrite };

#define ROWS 10
#define COLS 10

#define INIT_ROW vector<char>(COLS, ' ')
#define BORDER cout << "+"; for(int i = 0; i < 10; i++) cout << "-"; cout << "+" << endl

#define B cursor.second = 0
#define C fill(display.begin(), display.end(), INIT_ROW)
#define D if(cursor.first < ROWS - 1) cursor.first++
#define E fill(display[cursor.first].begin() + cursor.second, display[cursor.first].end(), ' ')
#define H cursor.first = cursor.second = 0
#define I mode = insert
#define L if(cursor.second > 0) cursor.second--
#define O mode = overwrite
#define R if(cursor.second < COLS - 1) cursor.second++
#define U if(cursor.first > 0) cursor.first--
#define NN char row = line[i] - '0'; char col = line[++i] - '0'; move_cursor(row, col)

#define WRITE_DISPLAY if(mode == insert) { for(int j = COLS - 1; j > cursor.second; j--) { display[cursor.first][j] = display[cursor.first][j - 1]; } } display[cursor.first][cursor.second] =

using namespace std;

vector<vector<char>> display(ROWS, INIT_ROW);
pair<int, int> cursor(0, 0);
Mode mode = overwrite;



void move_cursor(int r, int c)
{
  cursor.first = r;
  cursor.second = c;
};

void write_display(char ch)
{
  WRITE_DISPLAY ch;
  R;
}

void print_result(int n)
{
  cout << "Case " << n << endl;

  BORDER;
  for(vector<char> l : display)
  {
    cout << "|";
    for(char ch : l)
    {
      cout << ch;
    }
    cout << "|" << endl;
  }
  BORDER;

};

void proccess(string line)
{
  int n = line.length();
  for(int i = 0; i < n; i++)
  {
    if(line[i] == '^')
    {
      i++;
      if(line[i] == 'b') B;
      else if(line[i] == 'c') C;
      else if(line[i] == 'd') { D; }
      else if(line[i] == 'e') E;
      else if(line[i] == 'h') H;
      else if(line[i] == 'i') I;
      else if(line[i] == 'l') { L; }
      else if(line[i] == 'o') O;
      else if(line[i] == 'r') { R; }
      else if(line[i] == 'u') { U; }
      else if(line[i] == '^') write_display('^');
      else { NN; }
    }
    else write_display(line[i]);
  }
}

int main(int argc, char** argv)
{
  int n = 0;
  while(1)
  {
    int command_n;
    scanf("%d\n", &command_n);
    if(command_n == 0) break;

    C;
    H;
    for(int i = 0; i < command_n; i++)
    {
      string line;
      getline(cin, line);

      proccess(line);
    }

    print_result(++n);
  }

  return 0;
};
