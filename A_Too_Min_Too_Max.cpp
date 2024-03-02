#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

vector<int> minCoins(vector<int> &coins, int target)
{
  vector<int> dp(target + 1, INT_MAX);
  dp[0] = 0;

  for (int coin : coins)
  {
    for (int i = coin; i <= target; ++i)
    {
      if (dp[i - coin] != INT_MAX)
      {
        dp[i] = min(dp[i], dp[i - coin] + 1);
      }
    }
  }

  vector<int> usedCoins;
  int remaining = target;
  for (int i = coins.size() - 1; i >= 0; --i)
  {
    while (remaining >= coins[i] && dp[remaining] == dp[remaining - coins[i]] + 1)
    {
      usedCoins.push_back(coins[i]);
      remaining -= coins[i];
    }
  }
  return usedCoins;
}

int main()
{
  vector<int> coins = {1, 3, 6, 10, 15};
  int target = 9856456;

  vector<int> result = minCoins(coins, target);

  cout << "Coins to make " << target << ": ";
  for (int coin : result)
  {
    cout << coin << " ";
  }
  cout << endl;

  return 0;
}
