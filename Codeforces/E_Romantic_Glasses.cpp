#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
  ll t;
  cin >> t;
  while (t--)
  {
    ll n, k;
    cin >> n >> k;
    ll product = 1;
    for (int i = 0; i < n; i++)
    {
      ll x;
      cin >> x;
      product *= x;
    }
    if (2023 % product == 0)
    {
      cout << "YES" << endl;
      cout << 2023 / product << " ";
      for (int i = 1; i <= k - 1; i++)
      {
        cout << 1 << " ";
      }
      cout << endl;
    }
    else
    {
      cout << "NO" << endl;
    }
  }

  return 0;
}