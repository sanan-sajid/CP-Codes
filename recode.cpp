#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t = 1;
  cin >> t;
  while (t--)
  {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    vector<ll> v(100, 0);
    for (int i = 0; i < n; i++)
    {
      v[s[i] - 'a']++;
    }
    ll ans1 = 0, ans2 = 0;
    ans1 += max(v[1], v[2]) + v[6];
    ans2 += v[3] + max(v[4], v[5]) + v[6];
    cout << max(ans1, ans2) + v[0] << endl;
  }
  return 0;
}