#include <bits/stdc++.h>
using namespace std;

struct segtree
{
  int size;
  vector<long long> sums;
  void build(int n)
  {
    size = 1;
    while (size < n)
      size *= 2;
    sums.resize(2 * size, -1);
  }
};
int main()
{

  return 0;
}
