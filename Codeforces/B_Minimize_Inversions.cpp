#include <bits/stdc++.h>
using namespace std;
// 123456789
string s = "123456789";
vector<int> sequentialDigits(int low, int high)
{
  vector<int> res;
  for (int size = 1; size <= 9; size++)
  {
    for (int i = 0; i <= 9 - size; i++)
    {
      string temp;
      for (int k = i; k < i + size; k++)
      {
        temp += s[k];
      }
      int val = stoi(temp);
      if (val >= low && val <= high)
      {
        res.push_back(val);
      }
    }
  }

  return res;
}

int main()
{

  return 0;
}
