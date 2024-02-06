
#include <bits/stdc++.h>

#define MOD 1000000007

using namespace std;

int main()
{
  const int modo = 1e9 + 7;

  int n;
  cin >> n;
  if (n < 10)
  {
    cout << 1;
    return 0;
  }
  vector<int> dp(n + 1, 1e9);
  dp[0] = 0;
  for (int i = 1; i <= 9; i++)
  {
    dp[i] = 1;
  }
  for (int i = 10; i <= n; i++)
  {
    int x = i;
    while (x != 0)
    {
      // cout << i - (x % 10) << " " << dp[i - (x % 10)] << endl;
      if (i - (x % 10) >= 0)
        dp[i] = min(dp[i], 1 + dp[i - (x % 10)]);

      x = x / 10;
    }
  }

  cout << dp[n];

  return 0;
}