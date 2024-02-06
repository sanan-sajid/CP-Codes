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
int power(int x, int y)
{
  unsigned long long res = 1;
  x = x;
  while (y > 0)
  {
    if (y & 1)
      res = (res * x);
    y = y >> 1;
    x = (x * x);
  }
  return res;
}
const int m = 1e9 + 7;
int sum = 0;
int n;
int f(vector<int> &v, int k, int index, int currSum, vector<vector<int>> &dp)
{
  if (currSum >= k)
    return 0;

  if (index == n)
    return 1; // k>=sum already taken care above
  if (dp[index][currSum] != -1)
    return dp[index][currSum];
  return dp[index][currSum] = (f(v, k, index + 1, currSum, dp) % m + f(v, k, index + 1, currSum + v[index], dp) % m) % m;
}
int f1(vector<int> &v, int k, int index, int currSum, vector<vector<int>> &dp)
{
  if (currSum >= k)
    return 0;
  if (index == n)
  {
    if (currSum < k && sum - currSum < k)
      return 1;
    else
      return 0;
  }
  if (dp[index][currSum] != -1)
    return dp[index][currSum];
  return dp[index][currSum] = (f1(v, k, index + 1, currSum, dp) % m + f1(v, k, index + 1, currSum + v[index], dp) % m) % m;
}
int countPartitions(vector<int> &nums, int k)
{
  // vector<int> dp2();
  n = nums.size();
  vector<vector<int>> dp1(n, vector<int>(k + 1, -1));
  vector<vector<int>> dp2(n, vector<int>(k + 1, -1));
  for (auto it : nums)
  {
    sum += it;
  }

  return (power(2, n) - 2 * f(nums, k, 0, 0, dp1) + f1(nums, k, 0, 0,dp2));
}

int main()
{
  vector<int> v = {1, 2, 3, 4};
  cout << countPartitions(v, 4);
  return 0;
}
