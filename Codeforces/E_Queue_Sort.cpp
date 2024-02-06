#include <bits/stdc++.h>
using namespace std;

set<int> s = {4, 9, 16, 25};
int helper(vector<int> &nums, int index, int curr)
{
  if (index == nums.size())
    return 1;
  int notTaken = helper(nums, index + 1, curr);
  int Taken = 0;
  int temp = curr * nums[index];
  temp = sqrt(temp);
  if (temp * temp == curr * nums[index])
  {
    Taken = helper(nums, index + 1, curr * nums[index]) + 1;
    return Taken * notTaken;
  }
  return notTaken;
}
int squareFreeSubsets(vector<int> &nums)
{
  return helper(nums, 0, 1);
}

int main()
{
  vector<int> v = {3, 4, 4, 5};
  cout << squareFreeSubsets(v);
  return 0;
}
