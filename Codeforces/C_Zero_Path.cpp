#include <bits/stdc++.h>

using namespace std;

#define int long long

#define MOD 1000000007

#define vi vector<int>

#define vpi vector<pair<int, int>>

#define inf (int)1e18

const int MAXN = 200000;

// int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199};
int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293};

void solve()
{

  int n;
  cin >> n;

  vector<int> a(n);

  vector<pair<int, int>> e, o;

  set<int> odd;

  for (int i = 0; i < n; i++)
  {

    cin >> a[i];

    if (a[i] % 2 == 0)
      e.push_back({i, a[i]});

    else
    {

      o.push_back({i, a[i]});

      odd.insert(a[i]);
    }
  }

  if (e.size() > 1)
  {

    cout << e[0].first + 1 << " " << e[1].first + 1 << endl;

    return;
  }
  bool flag1 = 0;

  if (o.size() > 1)
  {

    if (odd.size() == 1 && o[0].second == 1)
    {

      flag1 = 1;
    }

    else
    {
      int size = o.size();
      cout << o[0].first + 1 << " " << o[size - 1].first + 1 << endl;

      return;
    }
  }

  int s = 0;

  if (e.size() > 0)
    s = e[0].second + o[0].second;

  else
  {
    cout << -1 << endl;
    return;
  }

  for (int i = 0; i < 46; i++)
  {

    if (prime[i] == s)
    {

      cout << -1 << endl;

      return;
    }
  }

  cout << e[0].first + 1 << " " << o[0].first + 1 << endl;
}

signed main()
{

  ios_base::sync_with_stdio(0);

  cin.tie(0);

  cout.tie(0);

#ifndef ONLINE_JUDGE

  freopen("input.txt", "r", stdin);

  freopen("output.txt", "w", stdout);

#endif

  int t = 1;

  cin >> t;

  while (t--)

  {

    solve();
  }

  return 0;
}
