#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(v) v.begin(), v.end()
#define vi vector<int>
typedef long long ll;
const int n1 = 1e9 + 7;
const int MX = 1e9;
// === Segment Tree ===
struct Node;
struct Update;

template <typename T, typename Node = Node, typename Update = Update>
class SegmentTree
{
private:
  int size = 0;
  vector<Node> seg;

  void build(int start, int end, int ind, vector<T> &arr)
  {
    if (start == end)
    {
      seg[ind] = Node(arr[start]);
      return;
    }
    int mid = (start + end) / 2;
    int leftInd = 2 * ind + 1, rightInd = 2 * ind + 2;
    build(start, mid, leftInd, arr);
    build(mid + 1, end, rightInd, arr);
    seg[ind].merge(seg[leftInd], seg[rightInd]);
  }

  Node query(int start, int end, int ind, int left, int right)
  {
    if (start > right || end < left)
    {
      return Node();
    }
    if (start >= left && end <= right)
    {
      return seg[ind];
    }
    int mid = (start + end) / 2;
    int leftInd = 2 * ind + 1, rightInd = 2 * ind + 2;
    Node res;
    Node leftItem = query(start, mid, leftInd, left, right);
    Node rightItem = query(mid + 1, end, rightInd, left, right);
    res.merge(leftItem, rightItem);
    return res;
  }

  void update(int start, int end, int ind, int index, Update &u)
  {
    if (start == end)
    {
      u.apply(seg[ind]);
      return;
    }
    int mid = (start + end) / 2;
    int leftInd = 2 * ind + 1, rightInd = 2 * ind + 2;
    if (index <= mid)
      update(start, mid, leftInd, index, u);
    else
      update(mid + 1, end, rightInd, index, u);
    seg[ind].merge(seg[leftInd], seg[rightInd]);
  }

public:
  SegmentTree()
  {
  }

  SegmentTree(int n)
  {
    size = n;
    seg.resize(4 * size + 1);
  }

  SegmentTree(vector<T> &arr)
  {
    size = arr.size();
    seg.resize(4 * size + 1);
    build(arr);
  }

  void build(vector<T> &arr)
  {
    build(0, size - 1, 0, arr);
  }

  Node query(int left, int right)
  {
    return query(0, size - 1, 0, left, right);
  }

  void update(int index, int value)
  {
    Update u = Update(value);
    return update(0, size - 1, 0, index, u);
  }
};

struct Node
{
  long long sum;
  int mx, mn;
  long long andd;

  Node() : sum(0), mx(-MX), mn(MX), andd((1LL << 32) - 1) {}
  Node(int val) : sum(val), mx(val), mn(val), andd(val) {}

  void merge(Node &left, Node &right)
  {
    sum = left.sum + right.sum;
    mx = max(left.mx, right.mx);
    mn = min(left.mn, right.mn);
    andd = left.andd & right.andd;
  }
};

struct Update
{
  int val;

  Update() : val(0) {}
  Update(int v) : val(v) {}

  void apply(Node &node)
  {
    node.sum = val;
    node.mn = val;
    node.mx = val;
    node.andd = val;
  }
};
void primeFactors(int n, vector<int> &v)
{
  while (n % 2 == 0)
  {
    v.push_back(2);
    n = n / 2;
  }
  for (int i = 3; i <= sqrt(n); i = i + 2)
  {
    while (n % i == 0)
    {
      v.push_back(i);
      n = n / i;
    }
  }
  if (n > 2)
    v.push_back(n);
}
int power(int x, int y, int p = n1)
{
  unsigned long long res = 1;
  x = x % p;
  while (y > 0)
  {
    if (y & 1)
      res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}

int sz = 1e6 + 5;
bool PrimeSieve[1000005]; // 1e6+5
void buildSieve()
{
  for (int i = 2; i <= sz; i++)
    PrimeSieve[i] = 1;
  PrimeSieve[0] = 0; //
  PrimeSieve[1] = 0; // 1 is neither prime nor composite
  for (int i = 2; i < sz; i++)
  {
    if (PrimeSieve[i] == 0)
      continue; // the current number itself is composite
    for (int j = 2; j * i < sz; j++)
    {
      PrimeSieve[i * j] = 0;
    }
  }
}

bool isPrime(int n)
{
  // O(sqrt(N))
  if (n == 1)
    return 0;
  for (int i = 2; i * i <= n; i++)
  {
    if (n % i == 0)
      return 0;
  }
  return 1;
}
/// ====================================PRIME utility ENDS here==================================================
int modInverse(int n, int p = n1) // using fermats little thm. [p needs to be prime which is mostly the case as mod value generally is 1e9+7]
{
  return power(n, p - 2, p);
}
// can also derive this using extended euclidean... however this has a much simpler code....

// =========================================Used to calculate nCr of higher values ===================================
int nCr(int n, int r, int p = n1) // faster calculation..
{
  if (n < r)
    return 0;

  if (r == 0)
    return 1;

  vector<int> fac(n + 1, 0);
  fac[0] = 1;
  for (int i = 1; i <= n; i++)
    fac[i] = (fac[i - 1] * i) % p;

  return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p;
}

int modFact(int n, int p = n1)
{
  if (n >= p)
    return 0;

  int result = 1;
  for (int i = 1; i <= n; i++)
    result = (result * i) % p;

  return result;
}
int nPr(int n, int r, int p = n1)
{
  return modFact(n, p) / modFact(n - r, p);
}
/// ====================================BIT TRICKS==================================================
// TO CHECK IF iTH BIT IS SET OR NOT
// for (int j = 0; j < 31; j++)
//             {
//                 if ((v[i] & (1 << j)))
//                 {
//                     setBit[j]++;
//                 }
//             }
/// ====================================BIT TRICKS ENDS HERE==================================================
/// ====================================Some learning here==================================================

// 1.never erase anything from ds(map,set,vector ,etc )while iterating , store the elements in another ds which to be
//   deleted then run another loop and use erase fxn.

/// ====================================End==================================================
// upper_bound(a.begin(),a.end(),x)-a.begin(); returns index ->arr[ind] > x
// lower_bound(a.begin(),a.end(),x)-a.begin(); returns index ->arr[ind] >= x
// MUST SORT THE ARRAY FIRST!! BEFORE USING UNIQUE
// n = unique(all(v)) - v.begin(); REMOVE DUPS AND IMP TO STORE NEW VALUE OF N SIZE OF ARRAY
int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t = 1;
  // cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<int> v(1e5 + 10);
    for (int i = 0; i < n; i++)
    {
      int x;
      cin >> x;
      v[x]++;
    }
    vector<int> dp(1e5 + 10);
    dp[0] = 0;
    dp[1] = v[1];
    for (int i = 2; i < v.size(); i++)
    {
      dp[i] = max(dp[i - 1], dp[i - 2] + v[i] * i);
    }

    cout << *max_element(all(dp)) << endl;
  }
  return 0;
}