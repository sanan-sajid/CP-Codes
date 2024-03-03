#include <bits/stdc++.h>
using namespace std;
struct segtree
{
  int size;
  vector<int> val;
  void init(int n)
  {
    size = 1;
    while (size < n)
      size *= 2;
    val.resize(2 * size, 0);
  }
  void build(vector<int> &a, int x, int lx, int rx)
  {
    if (rx - lx == 1)
    {
      // leaf
      if (lx < a.size())

      {
        if (a[lx] == 1)
        {
          val[x] = 1;
        }
      }
      return;
    }
    int mid = (lx + rx) / 2;
    build(a, 2 * x + 1, lx, mid);
    build(a, 2 * x + 2, mid, rx);
    val[x] = val[2 * x + 1] + val[2 * x + 2];
  }
  void build(vector<int> &a)
  {
    build(a, 0, 0, size);
  }
  void set(int i, int x, int lx, int rx)
  {
    if (rx - lx == 1)
    {
      // leaf
      val[x] = 1 - val[x];
      return;
    }
    int mid = (lx + rx) / 2;

    if (i < mid)
    {
      set(i, 2 * x + 1, lx, mid);
    }
    else
    {
      set(i, 2 * x + 2, mid, rx);
    }
    val[x] = val[2 * x + 1] + val[2 * x + 2];
  }
  void set(int i)
  {
    set(i, 0, 0, size);
  }
  int cal(int i, int x, int lx, int rx)
  {
    if (rx - lx == 1)
    {
      return lx;
    }
    int currVal = val[x];
    int l = val[2 * x + 1];
    int mid = (lx + rx) / 2;
    if (i >= l)
    {
      // go righht
      return cal(i - l, 2 * x + 2, mid, rx);
    }
    else
    {
      return cal(i, 2 * x + 1, lx, mid);
    }
  }
  int cal(int i)
  {
    return cal(i, 0, 0, size);
  }
};

int main()
{
  int n, q;
  cin >> n >> q;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  segtree sg;
  sg.init(n);
  sg.build(v);
  while (q--)
  {
    int type;
    cin >> type;
    if (type == 1)
    {
      int a;
      cin >> a;
      // update fnx to opp
      sg.set(a);
    }
    else
    {
      int a;
      cin >> a;
      cout << sg.cal(a) << endl;
      ;
      // get kth one
    }
  }

  return 0;
}
