
#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;

struct segtree
{
  int size;
  vector<int> maxi;
  void init(int n)
  {
    size = 1;
    while (size < n)
      size = size * 2; // we need size nearest to power of 2

    maxi.resize(2 * size, LONG_LONG_MIN);
  }

  void build(vector<int> &a, int x, int lx, int rx)
  {
    if (rx - lx == 1)
    {
      // leaf node
      if (lx < a.size())
      {
        maxi[x] = a[lx];
      }

      return;
    }
    int mid = (lx + rx) / 2;
    build(a, 2 * x + 1, lx, mid);
    build(a, 2 * x + 2, mid, rx);
    maxi[x] = max(maxi[2 * x + 1], maxi[2 * x + 2]);
  }
  void build(vector<int> &a)
  {
    build(a, 0, 0, size);
  }

  void set(int i, int v, int x, int lx, int rx)
  {
    if (rx - lx == 1)
    {
      // leaf node
      maxi[x] = v;

      // sg[x] = leaf;
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
    maxi[x] = max(maxi[2 * x + 1], maxi[2 * x + 2]);
  }
  void set(int i, int v)
  {
    set(i, v, 0, 0, size);
  }

  int cal(int val, int x, int lx, int rx)
  {

    // leaf node
    if (rx - lx == 1)
    {
      return lx;
    }
    int mid = (lx + rx) / 2;
    int left = maxi[2 * x + 1];
    int right = maxi[2 * x + 2];
    if (left >= val)
    {

      return cal(val, 2 * x + 1, lx, mid);
    }
    else
    {
      return cal(val, 2 * x + 2, mid, rx);
    }
  }
  int cal(int val)
  {
    if (maxi[0] < val)
    { // root
      return -1;
    }
    return cal(val, 0, 0, size);
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
  }
  sg.build(v);

  while (q--)
  {
    int idk;
    cin >> idk;
    int res = sg.cal(idk);
    if (res != -1)
    {
      cout << res + 1 << " ";
      sg.set(res, v[res] - idk);
      v[res] = v[res] - idk;
    }
    else
    {
      cout << 0 << " ";
    }

    // int type;
    // cin >> type;
    // if (type == 1)
    // {
    //   // change
    //   int a, b;
    //   cin >> a >> b;
    //   sg.set(a, b);
    // }
    // else
    // {
    //   int x;
    //   cin >> x;
    //   cout << sg.cal(x) << endl;
    // }
  }

  return 0;
}
