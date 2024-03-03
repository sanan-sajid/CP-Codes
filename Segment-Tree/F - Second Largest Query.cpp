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

  node combine(const node &a, const node &b)
  {
    node ans;
    if (a.num1 > b.num1)
    {
      ans.num1 = a.num1;
      ans.cnt1 += a.cnt1;
      if (a.num2 > b.num1)
      {
        ans.num2 = a.num2;
        ans.cnt2 += a.cnt2;
      }
      else if (a.num2 == b.num1)
      {
        ans.num2 = a.num2;
        ans.cnt2 += a.cnt2;
        ans.cnt2 += b.cnt1;
      }
      else
      {
        ans.num2 = b.num1;
        ans.cnt2 += b.cnt1;
      }
    }
    else if (a.num1 == b.num1)
    {
      ans.num1 = a.num1;
      ans.cnt1 += a.cnt1;
      ans.cnt1 += b.cnt1;
      if (a.num2 > b.num2)
      {
        ans.num2 = a.num2;
        ans.cnt2 += a.cnt2;
      }
      else if (a.num2 == b.num2)
      {
        ans.num2 = a.num2;
        ans.cnt2 += a.cnt2;
        ans.cnt2 += b.cnt2;
      }
      else
      {
        ans.num2 = b.num2;
        ans.cnt2 += b.cnt2;
      }
    }
    else if (a.num1 < b.num1)
    {
      ans.num1 = b.num1;
      ans.cnt1 += b.cnt1;
      if (b.num2 > a.num1)
      {
        ans.num2 = b.num2;
        ans.cnt2 += b.cnt2;
      }
      else if (b.num2 == a.num1)
      {
        ans.num2 = b.num2;
        ans.cnt2 += b.cnt2;
        ans.cnt2 += a.cnt1;
      }
      else
      {
        ans.num2 = a.num1;
        ans.cnt2 += a.cnt1;
      }
    }
    return ans;
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
    sg[x] = combine(sg[2 * x + 1], sg[2 * x + 2]);
  }
  void set(int i, int v)
  {

    set(i, v, 0, 0, size);
  }
  // int sum(int l, int r, int x, int lx, int rx)
  // {
  //   // do not intersect
  //   if (lx >= r || rx <= l)
  //     return 0;
  //   // fully overlap
  //   else if (lx >= l && rx <= r)
  //   {
  //     return sums[x];
  //   }
  //   else
  //   {
  //     int mid = (lx + rx) / 2;
  //     return sum(l, r, 2 * x + 1, lx, mid) + sum(l, r, 2 * x + 2, mid, rx);
  //   }
  // }
  // int sum(int l, int r)
  // {
  //   return sum(l, r, 0, 0, size);
  // }
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
      return combine(cal(l, r, 2 * x + 1, lx, mid), cal(l, r, 2 * x + 2, mid, rx));
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
    sg.set(i, v[i]);
  }
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
