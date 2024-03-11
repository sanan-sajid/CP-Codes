// https://atcoder.jp/contests/abc343/tasks/abc343_f
#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
struct node
{ // num1>=num2
  // int num1, num2, cnt1 = 0, cnt2 = 0;
  int seg = 0, suff = 0, pref = 0, sum = 0;
};
struct segtree
{
  int size;

  vector<int> sum;
  vector<node> sg;
  void init(int n)
  {
    size = 1;
    while (size < n)
      size = size * 2; // we need size nearest to power of 2
    // sums.resize(2 * size);
    // sg.resize(2 * size);
    sum.resize(2 * size);
    sg.resize(2 * size);
  }
  node com(node a, node b)
  {
    node res;
    res.seg = max({a.seg, b.seg, a.suff + b.pref});
    res.pref = max(a.pref, b.pref + a.sum);
    res.suff = max(b.suff, a.suff + b.sum);
    res.sum = a.sum + b.sum;
    return res;
  }
  void build(vector<int> &a, int x, int lx, int rx)
  {
    if (rx - lx == 1)
    {
      // leaf node
      // we have to check if this actually belong to array
      node leaf;
      if (lx < a.size())
      {
        if (a[lx] >= 0)
        {
          leaf.pref = a[lx];
          leaf.suff = a[lx];
          leaf.seg = a[lx];
          leaf.sum = a[lx];
        }
        else
        {
          leaf.pref = 0;
          leaf.suff = 0;
          leaf.seg = 0;
          leaf.sum = a[lx];
        }
      }
      sg[x] = leaf;
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

  void set(int i, int v, int x, int lx, int rx)
  {
    if (rx - lx == 1)
    {
      // leaf node
      node leaf;
      if (v > 0)
      {
        leaf.pref = v;
        leaf.suff = v;
        leaf.seg = v;
        leaf.sum = v;
      }
      else
      {
        leaf.pref = 0;
        leaf.suff = 0;
        leaf.seg = 0;
        leaf.sum = v;
      }
      sg[x] = leaf;
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
    // sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
    sg[x] = com(sg[2 * x + 1], sg[2 * x + 2]);
  }
  void set(int i, int v)
  {

    set(i, v, 0, 0, size);
  }

  node cal(int l, int r, int x, int lx, int rx)
  {
    if (lx >= r || rx <= l)
    {
      node leaf;
      leaf.pref = leaf.seg = leaf.suff = leaf.sum = 0;
      return leaf;
      // do not intersect
    }
    else if (lx >= l && rx <= r)
    {
      return sg[x];
    }
    else
    {
      int mid = (lx + rx) / 2;
      return com(cal(l, r, 2 * x + 1, lx, mid), cal(l, r, 2 * x + 2, mid, rx));
    }
  }
  node cal(int l, int r)
  {
    return cal(l, r, 0, 0, size);
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
  // cout << sg.cal(0, n).seg << endl;

  while (q--)
  {
    int a, b;
    cin >> a >> b;
    a--;
    sg.set(a, b);
    cout << sg.cal(0, n).seg << endl;
  }

  return 0;
}
