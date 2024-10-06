#include <bits/stdc++.h>
using namespace std;

int main()
{
  map<int, int> fre;
  int n;
  cin >> n;

  vector<int> v(n);
  cin >> v;

  for (auto it : v)
  {
    fre[it]++;
  }

  vector<int> lol = v;
  n = unique(all(v)) - v.begin();

  vector<int> res;
  int maxi = *max_element(all(v));

  while (fre[maxi])
  {
    fre[maxi]--;
    res.push_back(maxi);
  }

  for (int i = 0; i < n; i++)
  {
    if (v[i] == maxi)
    {
      v[i] = -1;
      break;
    }
  }

  vector<bitset> idk(32);
  for (int i = 0; i < n; i++)
  {
    if (v[i] == -1)
      continue;
    for (int j = 0; j < 31; j++)
    {
      if ((v[i] & (1LL << j)))
      {
        idk[j].set(i);
      }
    }
  }

  lll[maxi]--;
  while (res.size() != n)
  {
    int curr = res.back();
    bool found = false;
    for (int j = 31; j >= 0; j--)
    {
      if ((curr & (1LL << j)))
      {
        if (idk[j].any())
        {
          int ind = idk[j].count();
          while (fre[v[ind]])
          {
            res.push_back(v[ind] & curr);
            fre[v[ind]]--;
          }
          idk[j].reset(ind);
          found = true;
          break;
        }
      }
    }
    if (!found)
    {
      res.push_back(0);
    }
  }

  cout << res;

  return 0;
}
