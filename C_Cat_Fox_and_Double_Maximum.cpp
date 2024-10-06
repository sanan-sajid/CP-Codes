#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
class Solution
{
public:
  long long sumDigitDifferences(vector<int> &nums)
  {
    int n = nums.size();
    long long res = 0;
    int digit = to_string(nums[0]).size();
    for (int i = 0; i < digit; i++)
    {
      map<int, int> mp;
      for (int j = 0; j < n; j++)
      {
        mp[((int)(nums[j] % (int)pow(10, i + 1)) / pow(10, i))]++;
      }
      res += ((long long(n) * (n - 1))) / 2;
      for (auto it : mp)
      {

        res -= (it.second * (it.second - 1)) / 2;
      }
    }
    cout << res;
  }
};
int32_t main()
{

  return 0;
}
