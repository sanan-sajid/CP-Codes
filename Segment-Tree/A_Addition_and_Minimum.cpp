#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
// const int N = 1e5 + 5;
struct segtree
{

  int size;
  vector<int> mini, lazy;
  void init(int n)
  {
    size = 1;
    while (size < n)
    {
      size *= 2;
    }
    mini.resize(2 * size, LONG_LONG_MAX);
    lazy.resize(2 * size, 0);
  }
  // Update a single node along with its lazy value
  void upd(int val, int x)
  {
    mini[x] += val;
    lazy[x] += val;
  }
  // Propagate lazy values to children
  void shift(int x, int lx, int rx)
  { // no pending updates
    if (lazy[x] == 0)
      return;
    int mid = (lx + rx) / 2;
    upd(lazy[x], 2 * x + 1);
    upd(lazy[x], 2 * x + 2);
    lazy[x] = 0;
  }

  void build(vector<int> &a, int x, int lx, int rx)
  {
    if (rx - lx == 1)
    {
      if (lx < a.size())
      {
        mini[x] = a[lx];
      }
      return;
    }
    int mid = (lx + rx) / 2;
    build(a, 2 * x + 1, lx, mid);
    build(a, 2 * x + 2, mid, rx);
    mini[x] = min(mini[2 * x + 1], mini[2 * x + 2]);
  }
  void build(vector<int> &a)
  {
    build(a, 0, 0, size);
  }
  void add(int val, int l, int r, int x, int lx, int rx)
  {
    if (lx >= r || rx <= l)
      return;
    if (lx >= l && rx <= r)
    {
      // inside
      upd(val, x);
      return;
    }
    int mid = (lx + rx) / 2;
    shift(x, lx, rx); // propage to childs
    add(val, l, r, 2 * x + 1, lx, mid);
    add(val, l, r, 2 * x + 2, mid, rx);
    mini[x] = min(mini[2 * x + 1], mini[2 * x + 2]);
  }
  void add(int l, int r, int val)
  {
    add(val, l, r, 0, 0, size);
  }
  int query(int l, int r, int x, int lx, int rx)
  {
    if (lx >= r || rx <= l)
      return LONG_LONG_MAX;
    if (lx >= l && rx <= r)
    {
      // no need to propage
      // imp node store things that need to send
      // to child , at parent node already ho gya!!
      return mini[x];
    }
    int mid = (lx + rx) / 2;
    shift(x, lx, rx); // propogate!!
    return min(query(l, r, 2 * x + 1, lx, mid), query(l, r, 2 * x + 2, mid, rx));
  }
  int query(int l, int r)
  {
    return query(l, r, 0, 0, size);
  }
};

int32_t main()
{
  int n, q;
  cin >> n >> q;
  vector<int> v(n);
  // for (int i = 0; i < n; i++)
  //   cin >> v[i];
  segtree sg;
  sg.init(n);
  sg.build(v);
  // cout << sg.query(0, 1) << endl;
  while (q--)
  {
    int type;
    cin >> type;
    int l, r;
    cin >> l >> r;
    if (type == 1)
    {
      int val;
      cin >> val;
      // add v to seg
      // cout << val << endl;
      //
      sg.add(l, r, val);
    }
    else
    {
      cout << sg.query(l, r) << endl;
    }
  }

  return 0;
}
