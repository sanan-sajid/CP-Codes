#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    ll n;
    cin >> n;
    int ans = 0;
    map<ll, ll> m;
    ll a[n];
    for (int i = 0; i < n; i++)
      cin >> a[i];
    m[0] = 1;
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
      if (i % 2 == 0)
      {
        sum = sum + a[i];
      }
      else
      {
        sum = sum - a[i];
      }
      if (m[sum])
        ans = 1;
      else
        m[sum]++;
    }
    if (ans)
    {
      cout << "YES" << endl;
    }
    else
    {
      cout << "NO" << endl;
    }
  }
}