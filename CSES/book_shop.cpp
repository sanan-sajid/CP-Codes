#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--)
  {
    int n, x;
    cin >> n >> x;
    vector<int> cost(n), pages(n);
    for (int i = 0; i < n; i++)
    {
      cin >> cost[i];
    }
    for (int i = 0; i < n; i++)
    {
      cin >> pages[i];
    }

    // vector<vector<int>> dp(n + 1, vector<int>(x + 1));
    vector<vector<int>> dp(100001, vector<int>(1001));
    for (int i = 0; i <= n; i++)
    {
      for (int j = 0; j <= x; j++)
      {
        // base cases
        if (j == 0)
        {
          dp[i][j] = 0;
        }
        else if (i == 0)
        {
          if (j >= cost[0])
            dp[i][j] = pages[0];
          else
            dp[i][j] = 0;
        }
        else
        {
          int notTaken = dp[i - 1][j];
          int taken = -1e9;
          if (j - cost[i] >= 0)
            taken = dp[i - 1][j - cost[i]] + pages[i];
          dp[i][j] = max(taken, notTaken);
        }
      }
    }
    cout << dp[n][x];
    cout << '\n';
  }
  return 0;
}
