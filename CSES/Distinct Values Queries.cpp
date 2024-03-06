#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
struct segtree
{
  int size;
  vector<unordered_set<int>> sg;
  void init(int n)
  {
    size = 1;
    while (size < n)
      size = size * 2;

    sg.resize(2 * size);
  }
  unordered_set<int> com(unordered_set<int> &a, unordered_set<int> &b)
  {
    unordered_set<int> res;
    for (auto it : a)
      res.insert(it);
    for (auto it : b)
      res.insert(it);

    return res;
  }
  void build(vector<int> &a, int x, int lx, int rx)
  {
    if (rx - lx == 1)
    {
      if (lx < a.size())
        sg[x].insert(a[lx]);

      return;
    }
    int mid = (lx + rx) / 2;
    build(a, 2 * x + 1, lx, mid);
    build(a, 2 * x + 2, mid, rx);
    sg[x] = com(sg[2 * x + 1], sg[2 * x + 2]);
  }
  void build(vector<int> &a)
  {
    build(a, 0, 0, size);
  }
  unordered_set<int> cal(int l, int r, int x, int lx, int rx)
  {
    if (lx >= r || rx <= l)
    {
      unordered_set<int> idk;
      return idk;
    }
    if (lx >= l && rx <= r)
    {

      return sg[x];
    }
    int mid = (lx + rx) / 2;
    unordered_set<int> left = cal(l, r, 2 * x + 1, lx, mid);
    unordered_set<int> right = cal(l, r, 2 * x + 2, mid, rx);
    unordered_set<int> res = com(left, right);
    return res;
  }
  unordered_set<int> cal(int l, int r)
  {
    return cal(l, r, 0, 0, size);
  }
};

int32_t main()
{
  int n, q;

  cin >> n >> q;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
  {
    cin >> v[i];
  }
  segtree sg;
  sg.init(n);
  sg.build(v);
  for (int i = 0; i < q; i++)
  {
    int l;
    int r;
    cin >> l >> r;
    l--;
    cout << sg.cal(l, r).size() << endl;
  }

  return 0;
}