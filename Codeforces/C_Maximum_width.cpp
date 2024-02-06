#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class SegTree
{
  std::vector<int> segTree, lazy;

public:
  void buildTree(int &n, std::vector<int> a)
  {
    int num = n;
    n = (1 << int(std::ceil(log2(n * 1.0))));
    segTree.resize(2 * n);
    lazy.resize(2 * n);
    for (int i = 0; i <= num - 1; i++)
    {
      segTree[n + i] = a[i];
    }
    for (int i = n - 1; i >= 1; i--)
    {
      segTree[i] = segTree[2 * i] + segTree[2 * i + 1];
    }
  }

  int rangeQuery(int node = 0, int left = 0, int right = n - 1, int l, int r)
  {
    if (lazy[node])
    {
      segTree[node] += lazy[node] * (right - left + 1);
      if (left != right)
      {
        lazy[2 * node] += lazy[node];
        lazy[2 * node + 1] += lazy[node];
      }
      lazy[node] = 0;
    }
    if (left >= l && right <= r)
    {
      return segTree[node];
    }
    else if (right < l || left > r)
    {
      return 0;
    }
    else
    {
      int mid = (left + right) / 2;
      return rangeQuery(2 * node, left, mid, l, r) + rangeQuery(2 * node + 1, mid + 1, right, l, r);
    }
  }
  void pointUpdate(int n, int pos, int newVal)
  {
    segTree[n + pos] = newVal;
    for (int j = (n + pos) / 2; j >= 1; j /= 2)
    {
      segTree[j] = segTree[2 * j] + segTree[2 * j + 1];
    }
  }

  void rangeUpdate(int node, int left, int right, int l, int r, int newVal)
  {
    if (lazy[node])
    {
      segTree[node] += lazy[node] * (right - left + 1);
      if (left != right)
      {
        lazy[2 * node] += lazy[node];
        lazy[2 * node + 1] += lazy[node];
      }
      lazy[node] = 0;
    }
    if (left >= l && right <= r)
    {
      segTree[node] += newVal * (right - left + 1);
      if (left != right)
      {
        lazy[2 * node] += newVal;
        lazy[2 * node + 1] += newVal;
      }
    }
    else if (right < l || left > r)
    {
      return;
    }
    else
    {
      int mid = (left + right) / 2;
      rangeUpdate(2 * node, left, mid, l, r, newVal);
      rangeUpdate(2 * node + 1, mid + 1, right, l, r, newVal);
      segTree[node] = segTree[2 * node] + segTree[2 * node + 1];
    }
  }
};

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n, q;
    cin >> n >> q;
    vector<int> V(n);
    for (int i = 0; i < n; i++)
      cin >> V[i];
    SegTree seg;
    vector<int> range(n);
    seg.buildTree(n, range);
    while (q--)
    {
      int a;
      cin >> a;
      if (a == 1)
      {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        seg.rangeUpdate(1, 0, n - 1, l, r, 1);
      }
      else
      {
        int u;
        cin >> u;
        u--;
        int times = seg.rangeQuery(1, 0, n - 1, u, u);
        int x = V[u];
        // cout << times;
        while (times != 0 && x / 10 != 0)
        {
          x = sumOfDigits(x);

          times--;
        }

        cout << x << endl;
      }
    }
  }
  return 0;
}
