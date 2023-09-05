#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

int main()
{
  int n;
  scanf("%d", &n);

  for(int i = 0; i < n; i++)
  {
    vector<int> ret;

    int m;
    scanf("%d", &m);

    int number_array_first[m];
    int number_array_second[m];

    for(int j = 0; j < m; j++)
    {
      int first, second;
      scanf("%d%d", &first, &second);

      number_array_first[j] = first;
      number_array_second[j] = second;
    }

    bool overflow = false;

    for(int j = m - 1; j >= 0; j--)
    {
      int sum_actual_number_order = number_array_first[j] + number_array_second[j];

      if(overflow)
        sum_actual_number_order++;

      overflow = sum_actual_number_order >= 10;

      ret.push_back(sum_actual_number_order % 10);
    }

    if(i > 0)
      printf("\n");

    for(int j = ret.size() - 1; j >= 0; j--)
      printf("%d", ret[j]);
    printf("\n");
  }

  return 0;
};
