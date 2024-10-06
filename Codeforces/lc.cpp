#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
vector<int> jugglerSequence(int n)
{
  vector<int> res;
  while (n != 1)
  {
    res.push_back(n);
    if (n % 2)
    {
      n = (int)(pow(n, 1.5));
    }
    else
    {
      n = (int)(pow(n, 0.5));
    }
  }
  return res;
}
int32_t main()
{

  return 0;
}
