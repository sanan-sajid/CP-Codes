#include <bits/stdc++.h>
using namespace std;
bool isPos(map<char, int> &mp, map<char, int> &mp1)
{
  bool pos = 1;
  for (auto it : mp)
  {
    if (mp1[it.first] < it.second)
    {
      pos = 0;
      break;
    }
  }
  return pos;
}
string minWindow(string s, string t)
{
  int n = s.size();

  map<char, int> mp;
  for (auto it : t)
    mp[it]++;
  string res;
  int sizeOfRes = INT_MAX;
  map<char, int> mp1;
  int i = 0, j = 0;
  while (j < n)
  {
    while (isPos(mp, mp1))
    {
      mp1[s[i]]--;
      i++;
      if (sizeOfRes > (j - i + 1))
      {
        res = s.substr(i, j - i + 1);
        sizeOfRes = j - i + 1;
      }
    }

    mp1[s[j]]++;
    j++;
  }

  return res;
}

int main()
{

  return 0;
}
