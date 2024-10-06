#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <unordered_set>
#include <list>
#include <iterator>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <bitset>
#include <random>
#include <map>
#include <unordered_map>
#include <stdio.h>
#include <complex>
#include <math.h>
#include <cstring>
#include <chrono>
#include <string>
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"

using namespace std;
using namespace __gnu_pbds;

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <class key, class value, class cmp = std::less<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;

// find_by_order(k)  returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;

#define inf 2e18
#define ll long long
#define FAIZAN                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);                    \
  cout.tie(NULL)
const ll mod = 1e9 + 7;

vector<ll> sieve(int n)
{
  int *arr = new int[n + 1]();
  vector<ll> vect;
  for (int i = 2; i <= n; i++)
    if (arr[i] == 0)
    {
      vect.push_back(i);
      for (int j = 2 * i; j <= n; j += i)
        arr[j] = 1;
    }
  return vect;
}

ll inv(ll i)
{
  if (i == 1)
    return 1;
  return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;
}

ll mod_mul(ll a, ll b)
{
  a = a % mod;
  b = b % mod;
  return (((a * b) % mod) + mod) % mod;
}

ll mod_add(ll a, ll b)
{
  a = a % mod;
  b = b % mod;
  return (((a + b) % mod) + mod) % mod;
}

ll gcd(ll a, ll b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

ll ceil_div(ll a, ll b) { return a % b == 0 ? a / b : a / b + 1; }

ll pwr(ll a, ll b)
{
  a %= mod;
  ll res = 1;
  while (b > 0)
  {
    if (b & 1)
      res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}

ll helper(ll idx, ll k, vector<vector<ll>> &vp, vector<vector<ll>> &dp)
{
  if (k <= 0)
  {
    return 0;
  }

  if (idx >= (ll)vp.size())
  {
    return 1e9;
  }

  if (dp[idx][k] != -1)
  {
    return dp[idx][k];
  }

  ll notTake = 0 + helper(idx + 1, k, vp, dp);

  ll take = 1e9;

  for (int i = 1; i < vp[idx].size(); i++)
  {
    take = min(take, vp[idx][i] + helper(idx + 1, k - i, vp, dp));
  }

  return dp[idx][k] = min(take, notTake);
}

int main()
{
  FAIZAN;
  int t;
  cin >> t;
  while (t--)
  {
    ll n, k;
    cin >> n >> k;
    vector<pair<ll, ll>> vp(n);
    for (int i = 0; i < n; i++)
    {
      cin >> vp[i].first >> vp[i].second;
      // swap(vp[i].first,vp[i].second);
    }

    vector<vector<ll>> cost(n);
    for (int i = 0; i < n; i++)
    {
      ll x = vp[i].first;
      ll y = vp[i].second;
      vector<ll> tmp(x + y + 1, inf);

      for (int j = 1; j <= x + y; j++)
      {
        // traversing on number of rows
        for (int l = 0; l <= j; l++)
        {
          ll rows = l, cols = j - l;

          if (rows > x || cols > y)
            continue;

          ll value = rows * y + cols * x;
          value -= rows * cols;
          tmp[j] = min(tmp[j], value);
        }
      }
      cost[i] = tmp;
    }

    for (int i = 0; i < n; i++)
    {
      for (int j = 1; j < cost[i].size(); j++)
      {
        cout << "j = " << j << " = " << cost[i][j] << "\n";
      }
      cout << "\n";
    }

    vector<vector<ll>> dp(n + 2, vector<ll>(k + 2, -1));
    ll ans = helper(0, k, cost, dp);

    if (ans >= 1e9)
    {
      ans = -1;
    }

    cout << ans << "\n";
  }

  return 0;
}