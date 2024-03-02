#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<vector<int>> dp(505, vector<int>(505, -1));
int rec(int a, int b)
{
  if (a == b)
    return 0;
  if (dp[a][b] != -1)
    return dp[a][b];
  int res = INT_MAX;
  for (int i = 1; i < a; i++)
  {
    res = min(res, 1 + rec(a - i, b) + rec(i, b));
  }
  for (int i = 1; i < b; i++)
  {
    res = min(res, 1 + rec(a, i) + rec(a, b - i));
  }

  return dp[a][b] = res;
}

int main()
{
  int a, b;
  cin >> a >> b;
  // cout << rec(a, b);
  int dp[505][505];
  for (int i = 0; i <= a; i++)
  {
    for (int j = 0; j <= b; j++)
    {
      if (i == j)
      {
        dp[i][j] = 0;
      }
      else
      {
        int res = 1e9;
        for (int ii = 1; ii < i; ii++)
        {
          res = min(res, 1 + dp[i - ii][j] + dp[ii][j]);
        }
        for (int ii = 1; ii < j; ii++)
        {
          res = min(res, 1 + dp[i][j - ii] + dp[i][ii]);
        }
        dp[i][j] = res;
      }
    }
  }
  cout << dp[a][b];
  return 0;
}
