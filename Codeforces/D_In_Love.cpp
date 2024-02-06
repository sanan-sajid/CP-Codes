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
const int m = 1e9 + 7;
int n;
long long dp[100005][2];
long long helper(int n, int i, int prev)
{

  if (i == n)
  {
    return 1;
  }
  if (dp[i][prev] != -1)
    return dp[i][prev];
  // leaving empty
  long long a = helper(n, i + 1, 0) % m;
  // try to place B
  long long b = 0;
  if (prev == 0)
  {
    b = helper(n, i + 1, 1) % m;
  }
  return dp[i][prev] = ((a + b) % m);
}
int TotalWays(int N)
{

  n = N;
  memset(dp, -1, sizeof(dp));
  long long res = helper(n, 0, 0) % m;
  return (res * res) % m;
}

int main()
{
  int n;
  cin >> n;
  cout << TotalWays(n);

  return 0;
}
