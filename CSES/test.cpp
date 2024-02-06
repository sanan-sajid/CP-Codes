#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

/*---------------------CONSTANTS---------------------*/
#define M 1000000007
#define N 100005

/*---------------------INPUT/OUTPUT---------------------*/

template <typename typA>
istream &operator>>(istream &cin, vector<typA> &v)
{
  for (auto &x : v)
  {
    cin >> x;
  }
  return cin;
}
template <typename typA>
ostream &operator<<(ostream &cin, vector<typA> &v)
{
  for (auto &x : v)
  {
    cout << x << " ";
  }
  cout << "\n";
  return cout;
}

vector<ll> dp(N + 5, -1);

ll coin_comb(ll n, ll x, vector<ll> &v)
{
  ll way = 0;
  // base case
  if (x == 0)
  {
    return 1;
  }
  if (x < 0)
  {
    return 0;
  }
  // recursive
  if (dp[x] != -1)
  {
    return dp[x];
  }
  for (ll i = 0; i < v.size(); i++)
  {
    way = (way % M + coin_comb(n, x - v[i], v) % M) % M;
  }
  return dp[x] = way;
}

int main()
{
  ll t = 1;
  // cin>>t;
  while (t--)
  {
    ll n, x;
    cin >> n >> x;
    vector<ll> v(n);
    cin >> v;
    cout << (coin_comb(n, x, v) % M) << endl;
  }
  return 0;
}