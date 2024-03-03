#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
struct node
{
  int cnt, val;
};

struct segtree
{
  int size;

  vector<int> mini;
  vector<node> seg;

  void init(int n)
  {
    size = 1;
    while (size < n)
      size = size * 2; // we need size nearest to power of 2
    mini.resize(2 * size);
    seg.resize(2 * size);
  }
  node combine(node n1, node n2)
  {
    node idk;
    if (n1.val == n2.val)
    {
      idk.val = n1.val;
      idk.cnt = n1.cnt + n2.cnt;
    }
    else if (n1.val < n2.val)
    {
      idk.val = n1.val;
      idk.cnt = n1.cnt;
    }
    else
    {
      idk.val = n2.val;
      idk.cnt = n2.cnt;
    }

    return idk;
  }
  void set(int i, int v, int x, int lx, int rx)
  {
    if (rx - lx == 1)
    {

      seg[x].cnt = 1;
      seg[x].val = v;
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
    seg[x] = combine(seg[2 * x + 1], seg[2 * x + 2]);
  }
  void set(int i, int v)
  {
    set(i, v, 0, 0, size);
  }

  node minimum1(int l, int r, int x, int lx, int rx)
  {
    if (lx >= r || rx <= l)
    {
      node idk; // garbage idk
      idk.val = 1e18;
      idk.cnt = 0;
      return idk;
    }
    else if (lx >= l && rx <= r)
    {

      return seg[x];
    }
    else
    {
      int mid = (lx + rx) / 2;
      return combine(minimum1(l, r, 2 * x + 1, lx, mid), minimum1(l, r, 2 * x + 2, mid, rx));
    }
  }
  node minimum1(int l, int r)
  {
    return minimum1(l, r, 0, 0, size);
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
      // cout << sg.minimum(a, b) << endl;
      node temp = sg.minimum1(a, b);
      cout << temp.val << " " << temp.cnt << endl;
    }
  }

  return 0;
}
