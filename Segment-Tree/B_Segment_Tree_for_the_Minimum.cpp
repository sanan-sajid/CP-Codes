#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
struct segtree
{
  int size;
  // vector<int> sums;
  vector<int> mini;
  void init(int n)
  {
    size = 1;
    while (size < n)
      size = size * 2; // we need size nearest to power of 2
    mini.resize(2 * size);
  }
  void set(int i, int v, int x, int lx, int rx)
  {
    if (rx - lx == 1)
    {
      // leaf node
      mini[x] = v;
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
    mini[x] = min(mini[2 * x + 1], mini[2 * x + 2]);
  }
  void set(int i, int v)
  {
    set(i, v, 0, 0, size);
  }

  int minimum(int l, int r, int x, int lx, int rx)
  { // do not intersect
    if (lx >= r || rx <= l)
      return 1e18;
    else if (lx >= l && rx <= r)
    {
      return mini[x];
    }
    else
    {
      int mid = (lx + rx) / 2;
      return min(minimum(l, r, 2 * x + 1, lx, mid), minimum(l, r, 2 * x + 2, mid, rx));
    }
  }
  int minimum(int l, int r)
  {
    return minimum(l, r, 0, 0, size);
  }
};
int32_t main()
{
  int n, q;
  cin >> n >> q;
  segtree sg;
  sg.init(n);
  vector<int> v(n);
  for (int i = 0; i < n; i++)
  {
    cin >> v[i];
    sg.set(i, v[i]);
  }
  while (q--)
  {
    int type, a, b;
    cin >> type >> a >> b;
    if (type == 1)
    { // set new value
      sg.set(a, b);
    }
    else
    {
      cout << sg.minimum(a, b) << endl;
    }
  }

  return 0;
}
