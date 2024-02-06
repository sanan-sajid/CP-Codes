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
vector<int> dp(1e5, -1);
bool rec(vector<int> &nums, int index)
{
  if (index == nums.size())
    return 1;

  if (dp[index] != -1)
    return dp[index];
  // type 1: 2 equal
  bool type1 = false;
  if (index + 1 < nums.size() && nums[index + 1] == nums[index])
  {
    type1 = rec(nums, index + 2);
  }
  bool type2 = false;
  if (index + 2 < nums.size() && nums[index + 1] == nums[index] && nums[index] == nums[index + 2])
  {
    type2 = rec(nums, index + 3);
  }
  bool type3 = false;
  if (index + 2 < nums.size() && nums[index + 1] - 1 == nums[index] && nums[index] == nums[index + 2] - 2)
  {
    type2 = rec(nums, index + 3);
  }

  return dp[index]=(type1 || type2 || type3);
}
bool validPartition(vector<int> &nums)
{
  return rec(nums, 0);
}

int main()
{

  return 0;
}
