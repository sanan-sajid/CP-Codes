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

  int rangeQuery(int node, int left, int right, int l, int r)
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

// intialization
SegTree seg;
vector<int> range(n);
seg.buildTree(n, range);

seg.rangeUpdate(1, 0, n - 1, l, r, 1);
int times = seg.rangeQuery(1, 0, n - 1, u, u);
// first 3 parameter will be same 1,0,n-1