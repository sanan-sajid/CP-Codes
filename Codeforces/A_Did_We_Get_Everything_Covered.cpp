#include <bits/stdc++.h>
using namespace std;

int findMinimumXNotDivisor(int i)
{
  int x = 2; // Start checking from 2, as 1 is always a divisor
  while (true)
  {
    if (i % x != 0)
    {
      return x; // Found the minimum x that is not a divisor
    }
    x++;
  }
}

int main()
{
  for (int i = 2; i < 100; i += 2)
  {
    cout << i << " " << findMinimumXNotDivisor(i) << '\n';
  }

  return 0;
}
