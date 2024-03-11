#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
struct segtree
{
  int size;
  vector<int> sums;
  void init(int n)
  {
    size = 1;
    while (size < n)
      size = size * 2; // we need size nearest to power of 2
    sums.resize(2 * size, 0);
  }
  void set(int i, int v, int x, int lx, int rx)
  {
    if (rx - lx == 1)
    {
      // leaf node
      sums[x] = v;
      return;
    }
    int mid = (lx + rx) / 2;
    if (i < mid)
    {
      // go left
      set(i, v, 2 * x + 1, lx, mid);
    }
    else
    {
      // go right
      set(i, v, 2 * x + 2, mid, rx);
    }
    sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
  }
  void set(int i, int v)
  {

    set(i, v, 0, 0, size);
  }
  int sum(int l, int r, int x, int lx, int rx)
  {
    // do not intersect
    if (lx >= r || rx <= l)
      return 0;
    // fully overlap
    else if (lx >= l && rx <= r)
    {
      return sums[x];
    }
    else
    {
      int mid = (lx + rx) / 2;
      return sum(l, r, 2 * x + 1, lx, mid) + sum(l, r, 2 * x + 2, mid, rx);
    }
  }
  int sum(int l, int r)
  {
    return sum(l, r, 0, 0, size);
  }
};
bool compareSecond(const std::pair<int, int> &a, const std::pair<int, int> &b)
{
  return a.second < b.second;
}
int32_t main()
{
  int n, q;
  cin >> n >> q;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
  {
    cin >> v[i];
  }
  vector<pair<int, int>> queries(q);
  for (int i = 0; i < q; i++)
  {
    cin >> queries[i].first >> queries[i].second;
  }
  sort(queries.begin(), queries.end(), compareSecond);
  // for (auto it : queries)
  //   cout << it.second << endl;

  segtree sg;
  sg.init(n);
  map<int, int> mp;
  int j = 0;
  vector<pair<int, int>> res;
  for (int i = 0; i < n; i++)
  {
    if (mp.find(v[i]) == mp.end())
    {
      // first time aya
      mp[v[i]] = i;
      sg.set(i, 1);
    }
    else
    {
      // already occured
      sg.set(mp[v[i]], 0);
      sg.set(i, 1);
      mp.erase(v[i]);
    }
    if (queries[j].second - 1 == i)
    {
      // cout << queries[j].second << " " << sg.sum(queries[j].first - 1, queries[j].second) << endl;

      res.push_back({i, sg.sum(queries[j].first - 1, queries[j].second)});
      j++;
    }
  }
  sort(res.begin(), res.end());
  for (auto it : res)
  {
    cout << it.second << endl;
  }

  return 0;
}
