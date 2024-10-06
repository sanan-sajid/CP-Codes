#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
int minMoves(vector<int> &nums, int k)
{
  long long kk=k;
  if (kk == 1)
    return 0;
  vector<int> ones;
  for (int i = 0; i < nums.size(); i++)
  {
    if (nums[i] == 1)
      ones.push_back(i);
  }
  int n = ones.size();
  vector<long long> pre(n);
  pre[0] = ones[0];
  for (int i = 1; i < n; i++)
    pre[i] = pre[i - 1] + ones[i];
  long long res = 1e18;
  for (int i = kk / 2; i < n - (kk - 1) / 2; i++)
  {
    long long left;
    if (i - kk / 2 - 1 >= 0)
      left = ones[i] * (kk / 2) - (((kk / 2) * ((kk / 2 + 1) * 1LL)) / 2) - pre[i - 1] + pre[i - kk / 2 - 1];
    else
      left = ones[i] * (kk / 2) - ((((kk / 2) * 1LL) * ((kk / 2 + 1) * 1LL)) / 2LL) - pre[i - 1];
    long long right;
    right = (-1LL * (ones[i] * ((kk - 1) / 2))) - ((((kk - 1) * 1LL) / 2) * ((kk - 1) * 1LL / 2 + 1)) / 2 + (pre[i + (kk - 1) / 2] - pre[i]);
    cout << left << " " << right << endl;
    res = min(res, left + right);
  }

  return res;
}
int32_t main()
{

  return 0;
}
