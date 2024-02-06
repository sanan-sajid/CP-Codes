#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> divideArray(vector<int> &nums, int k)
{
  sort(nums.begin(), nums.end());
  int n = nums.size();
  vector<vector<int>> res;
  int i = 0;
  int f = 1;
  while (i < n)
  {
    vector<int> temp(3);
    f = 1;
    for (int j = i; j < i + 3; j++)
    {
      temp[j - i] = nums[i];
    }
    for (int j = 0; j < 2; j++)
    {
      if (temp[j + 1] - temp[j] > k)
      {
        f = 0;
        break;
      }
    }
    if (f)
    {
      res.push_back(temp);
    }
    else
    {
      break;
    }
  }
  if (!f)
  {
    vector<vector<int>> idk;
    return idk;
  }

  return res;
}

int main()
{

  return 0;
}
