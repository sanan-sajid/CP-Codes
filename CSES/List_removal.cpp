#include <bits/stdc++.h>
using namespace std;
struct segtree
{
  int size;
  vector<int> sg;
  void init(int n)
  {
    size = 1;
    while (size < n)
      size *= 2;
    sg.resize(2 * size, 0);
    // build(0, 0, size);
  }

  void build(int x, int lx, int rx)
  {
    if (rx - lx == 1)
    {
      sg[x] = 1;
      return;
    }
    int mid = (lx + rx) / 2;
    build(2 * x + 1, lx, mid);
    build(2 * x + 2, mid, rx);
    sg[x] = sg[2 * x + 1] + sg[2 * x + 2];
  }
  void build()
  {
    build(0, 0, size);
  }

  int query(int i, int x, int lx, int rx)
  {
    if (rx - lx == 1)
    {
      // leaf node
      // cout << lx << " ";
      // sg[x] = 0;
      return lx;
    }
    int mid = (lx + rx) / 2;
    int l = sg[2 * x + 1];
    // int r = ;
    if (i > l)
    {
      // go right
      return query(i - l, 2 * x + 2, mid, rx);
      // sg[x] = sg[2 * x + 1] + sg[2 * x + 2];
      //
      // return l;
    }
    else
    {
      // go left
      return query(i, 2 * x + 1, lx, mid);
      // sg[x] = sg[2 * x + 1] + sg[2 * x + 2];

      // return r;
    }
  }
  int query(int i)
  {
    return query(i, 0, 0, size);
  }
  void set(int i, int x, int lx, int rx)
  {
    if (rx - lx == 1)
    {
      // leaf
      sg[x] = 0;
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
    sg[x] = sg[2 * x + 1] + sg[2 * x + 2];
  }
  void update(int i, int x, int lx, int rx)
  {
    if (rx - lx == 1)
    {
      // leaf
      // cout << lx << endl;

      sg[x] = 0;

      return;
    }
    int mid = (lx + rx) / 2;
    // int l = sg[2 * x + 1];
    // int r = ;
    if (i >= mid)
    {
      // go right
      update(i, 2 * x + 2, mid, rx);
    }
    else
    {
      // go left
      update(i, 2 * x + 1, lx, mid);
    }
    sg[x] = sg[2 * x + 1] + sg[2 * x + 2];
  }
  void update(int i)
  {
    update(i, 0, 0, size);
  }
  void set(int i)
  {
    set(i, 0, 0, size);
  }
};

int main()
{
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
  {
    cin >> v[i];
  }
  segtree sg;
  sg.init(n);
  sg.build();
  int q = n;
  while (q--)
  {
    int x;
    cin >> x;
    int temp = sg.query(x);
    cout << v[temp] << " ";
    // cout << v[temp] << " ";
    sg.set(temp);
  }

  return 0;
}
