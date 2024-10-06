#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
int f(int d, int i, int cnt)
{
  if (d == i)
    return 0;
  if (i > 2 * d || i < -2 * d)
    return 1e9;
  return 1 + min(f(d, i + cnt, cnt + 1), f(d, i - cnt, cnt + 1));
}
int minSteps(int d)
{
  return f(d, 0, 1);
}
int32_t main()
{

  minSteps(110);
  return 0;
}
