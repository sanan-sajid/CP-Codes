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

int countSubarrays(vector<int> &nums, int k)
{
  int n = nums.size();
  vector<int> nums1(n);
  for (int i = 0; i < n; i++)
  {
    if (nums[i] > k)
      nums1[i] = 1;
    else if (nums[i] < k)
      nums1[i] = -1;
    else
      nums1[i] = 0;
  }
  for (auto it : nums1)
    cout << it << " ";
  cout << endl;
  map<int, int> mp;
  int currSum = 0;
  for (int i = 0; i < n; i++)
  {
    if (nums[i] == k)
      break;
    currSum += nums1[i];
    mp[currSum]++;
    // cout << currSum;
  }
  int res = 1; // as k will be present

  int i = 0;
  while (nums[i] != k)
    i++;
  i++;

  for (; i < n; i++)
  {
    currSum += nums1[i];
    // cout << currSum;

    res += mp[currSum] + mp[currSum - 1];
  }
  return res;
}

int main()
{
  vector<int> v = {2, 3, 1};
  cout << countSubarrays(v, 3);

  return 0;
}
