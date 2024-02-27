#include <bits/stdc++.h>
#define int long long

using namespace std;

vector<int> a, seg, lazy;
int n, m;
// Update a single node along with its lazy value
void upd(int id, int l, int r, int val) {
  seg[id] += val;
  lazy[id] += val;
}


// Propagate lazy values to children
void shift(int id, int l, int r) {
  if (lazy[id] == 0) return;
  int mid = (l + r) / 2;
  upd(id * 2, l, mid, lazy[id]);
  upd(id * 2 + 1, mid, r, lazy[id]);
  lazy[id] = 0;
}

// Range is [l,r-1] or [l,r)
void build(int id = 1, int l = 0, int r = n) {
  if (r - l == 1) {
    seg[id] = a[l];
    return;
  }
  int mid = (l + r) / 2;
  build(id * 2, l, mid);
  build(id * 2 + 1, mid, r);
  seg[id] = min(seg[id * 2], seg[id * 2 + 1]);
}
// Time complexity: O(n)

const int inf = 1e18;

// Finds minimum in a range [x,y) or [x,y-1]
int query(int x, int y, int id = 1, int l = 0, int r = n) {
  if (l >= y || r <= x) return inf;
  if (l >= x && r <= y) return seg[id];
  int mid = (l + r) / 2;
  shift(id, l, r);
  int l_ans = query(x, y, id * 2, l, mid);
  int r_ans = query(x, y, id * 2 + 1, mid, r);
  return min(l_ans, r_ans);
}
// Time complexity: O( log(N) )



// Increase all elements in range [x,y) or [x,y-1] by val
void increase(int x, int y, int val, int id = 1, int l = 0, int r = n) {
  if (l >= y || r <= x) return;
  if (l >= x && r <= y) {
    upd(id, l, r, val);
    return;
  }
  int mid = (l + r) / 2;
  shift(id, l, r);
  increase(x, y, val, id * 2, l, mid);
  increase(x, y, val, id * 2 + 1, mid, r);
  seg[id] = min(seg[id * 2], seg[id * 2 + 1]);
}
// Time complexity: O( log(N) )

int32_t main() {
  cin >> n >> m;

  a.resize(n);
  seg.resize(4 * n + 1);
  lazy.resize(4 * n + 1);

  build();

  while (m--) {
    int type;
    cin >> type;
    if (type == 1) {
      int x, y, val;
      cin >> x >> y >> val;
      increase(x, y, val);
    } else {
      int x, y;
      cin >> x >> y;
      cout << query(x, y) << '\n';
    }
  }

  return 0;
}

