#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define all(v) v.begin(), v.end()
#define vi vector<int>
typedef long long ll;
const int n1 = 1e9 + 7;
const int MX = 1e9;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

// ================================== take ip/op like vector,pairs directly!==================================
template <typename typC, typename typD>
istream &operator>>(istream &cin, pair<typC, typD> &a) { return cin >> a.first >> a.second; }
template <typename typC>
istream &operator>>(istream &cin, vector<typC> &a)
{
  for (auto &x : a)
    cin >> x;
  return cin;
}
template <typename typC, typename typD>
ostream &operator<<(ostream &cout, const pair<typC, typD> &a) { return cout << a.first << ' ' << a.second; }
template <typename typC, typename typD>
ostream &operator<<(ostream &cout, const vector<pair<typC, typD>> &a)
{
  for (auto &x : a)
    cout << x << '\n';
  return cout;
}
template <typename typC>
ostream &operator<<(ostream &cout, const vector<typC> &a)
{
  int n = a.size();
  if (!n)
    return cout;
  cout << a[0];
  for (int i = 1; i < n; i++)
    cout << ' ' << a[i];
  return cout;
}
// ===================================END Of the input module ==========================================

int modPower(int x, int y, int p = n1)
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
int power(int x, int y)
{
  unsigned long long res = 1;
  x = x;
  while (y > 0)
  {
    if (y & 1)
      res = (res * x);
    y = y >> 1;
    x = (x * x);
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
int idk[1000005];

void helper(int n, vector<int> &v)
{
  for (int j = 1; j * j <= n; j++)
  {
    if (n % j == 0)
    {
      if (j == (n / j))
      {
        idk[j] = max(idk[j], n);
      }
      else
      {
        idk[j] = max(idk[j], n);
        idk[n / j] = max(idk[n / j], n);
      }
    }
  }
}
int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t = 1;
  const int m = 998244353;
  while (t--)
  {
    int n;
    cin >> n;
    buildSieve();
    memset(idk, -1, sizeof(idk));
    vector<int> v(n);
    cin >> v;
    // sort(all(v));
    // reverse(all(v));
    int res = 0;

    for (int i = 0; i < n; i++)
    {
      if (v[i] == 0)
        continue;
      if (PrimeSieve[i + 1])
      {
        // prime
        res = ((res % m) + ((v[i] % m) * (modPower(2, n - i - 1, m)) % m)) % m;
      }
      else
      {
        helper(i + 1);
        res = ((res % m) + (idk[i + 1] % m) * (modPower(2, n - i - 1, m)) % m) % m;

        // cout << idk[v[i]] << " " << modPower(2, n - i - 1, m) << endl;
      }
    }

    cout << res % m;

    cout << endl;
  }
  return 0;
}