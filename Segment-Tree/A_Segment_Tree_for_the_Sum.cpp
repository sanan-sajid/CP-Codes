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
    sums.resize(2 * size);
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
    // a--;
    if (type == 1)
    { // set new value
      sg.set(a, b);
    }
    else
    { // sum cal l to r
      cout << sg.sum(a, b) << endl;
    }
  }

  return 0;
}
