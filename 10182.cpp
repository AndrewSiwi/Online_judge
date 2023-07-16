#include <stdio.h>
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

#define COMB_COOR pair<int, int>

#define ADD_TO_HIVE hive.push_back(COMB_COOR(x, y)); i++
#define FOR_DIR for(int j = 0; j < radius; j++)

int main(int argc, char** argv)
{
  vector<COMB_COOR> hive;

  int i = 1;
  int x = 0;
  int y = 0;

  ADD_TO_HIVE;
  y++;
  int radius = 1;
  while(i < 100000)
  {
    ADD_TO_HIVE;

    //LEFT
    FOR_DIR
    {
      x--;
      ADD_TO_HIVE;
    }

    //UP
    FOR_DIR
    {
      y--;
      ADD_TO_HIVE;
    }

    //DIAG
    FOR_DIR
    {
      x++;
      y--;
      ADD_TO_HIVE;
    }

    //RIGHT
    FOR_DIR
    {
      x++;
      ADD_TO_HIVE;
    }

    //DOWN
    FOR_DIR
    {
      y++;
      ADD_TO_HIVE;
    }

    //CONST
    y++;
    FOR_DIR
    {
      ADD_TO_HIVE;
      x--;
      y++;
    }

    radius++;
  }

  while(1)
  {
    int in;
    cin >> in;

    if(cin.eof()) break;

    COMB_COOR out = hive[in - 1];
    cout << out.first << " " << out.second << endl;
  }

  return 0;
}
