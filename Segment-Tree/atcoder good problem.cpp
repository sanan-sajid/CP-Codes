// https://atcoder.jp/contests/abc343/tasks/abc343_f
#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
struct node
{ // num1>=num2
  int num1, num2, cnt1 = 0, cnt2 = 0;
};
struct segtree
{
  int size;
  // vector<int> sums;
  vector<node> sg;
  void init(int n)
  {
    size = 1;
    while (size < n)
      size = size * 2; // we need size nearest to power of 2
    // sums.resize(2 * size);
    sg.resize(2 * size);
  }
  void build(vector<int> &a, int x, int lx, int rx)
  {
    if (rx - lx == 1)
    {
      // leaf node
      // we have to check if this actually belong to array
      if (lx < a.size())
      {
        node leaf;
        leaf.num1 = a[lx];
        leaf.cnt1 = 1;
        leaf.num2 = LONG_LONG_MIN;
        leaf.cnt2 = 0;
        sg[x] = leaf;
      }
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
  node com(node a, node b)
  {
    map<int, int> mp;
    mp[LONG_LONG_MIN] = 0;
    mp[a.num1] += a.cnt1;
    mp[a.num2] += a.cnt2;
    mp[b.num1] += b.cnt1;
    mp[b.num2] += b.cnt2;
    node temp;
    auto it = mp.end();
    it--;
    temp.num1 = it->first;
    temp.cnt1 = it->second;
    it--;
    temp.num2 = it->first;
    temp.cnt2 = it->second;

    return temp;
  }

  void set(int i, int v, int x, int lx, int rx)
  {
    if (rx - lx == 1)
    {
      // leaf node
      node leaf;
      leaf.num1 = v;
      leaf.cnt1 = 1;
      leaf.num2 = LONG_LONG_MIN;
      leaf.cnt2 = 0;
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
      leaf.num1 = LONG_LONG_MIN;
      leaf.num2 = LONG_LONG_MIN;
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
    // sg.set(i, v[i]);
  }
  sg.build(v);
  while (q--)
  {
    int type, a, b;

    cin >> type >> a >> b;
    a--;

    if (type == 1)
    { // set new value
      sg.set(a, b);
    }
    else
    {
      cout << sg.cal(a, b).cnt2 << endl;
    }
  }

  return 0;
}
