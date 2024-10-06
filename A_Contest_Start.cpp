#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;

ll min(ll a, ll b)
{
  return a < b ? a : b;
}

ll max(ll a, ll b)
{
  return a > b ? a : b;
}

// Type alias for pair of long longs
using pll = pair<ll, ll>;

string solution(string &s)
{
  ll w = 0;
  ll e = 0;
  ll n = 0;

  for (int i = 0; i < s.length(); i++)
  {
    if (s[i] == 'N')
      n++;
    if (s[i] == 'W')
      w++;
    if (s[i] == 'E')
      e++;
  }

  ll left = -1 - 2 * w;
  ll right = 1 + 2 * e;
  ll up = n + 1;

  ll r = up;
  ll c = right - left;

  ll sx = n;
  ll sy = -left;

  vector<vector<bool>> vis(r, vector<bool>(c, false));
  vis[sx][sy] = true;
  ll ex = sx;
  ll ey = sy;

  for (int i = 0; i < s.length(); i++)
  {
    if (s[i] == 'N')
      sx--;
    if (s[i] == 'W')
      sy--;
    if (s[i] == 'E')
      sy++;
    vis[sx][sy] = true;
  }

  queue<pll> q;
  q.push({sx, sy});
  map<pll, pll> parent;
  parent[{sx, sy}] = {-1, -1};

  while (!q.empty())
  {
    ll x = q.front().first;
    ll y = q.front().second;
    q.pop();

    vector<pll> t = {{1, 0}, {0, -1}, {0, 1}};
    for (auto it : t)
    {
      ll x1 = x + it.first;
      ll y1 = y + it.second;

      if (x1 < r && y1 < c && x1 >= 0 && y1 >= 0)
      {
        if (!vis[x1][y1])
        {
          parent[{x1, y1}] = {x, y};
          vis[x1][y1] = true;
          q.push({x1, y1});
        }
        else if (x1 == ex && y1 == ey)
        {
          string res = "";
          ll px = x;
          ll py = y;

          while (px != -1 || py != -1)
          {
            ll dx = px - x1;
            ll dy = py - y1;

            if (dx == -1)
            {
              res += 'S';
            }
            else
            {
              if (dy == 1)
              {
                res += 'W';
              }
              else
              {
                res += 'E';
              }
            }
            x1 = px;
            y1 = py;

            px = parent[{x1, y1}].first;
            py = parent[{x1, y1}].second;
          }

          reverse(res.begin(), res.end());
          return res; // Returning the result
        }
      }
    }
  }
  return ""; // In case no solution is found, return an empty string
}
string solution1(string &forth)
{
  int r1 = 0;
  int r2 = count(forth.begin(), forth.end(), 'N');
  int mx = 0, mn = 0;
  int cur = 0;
  for (auto c : forth)
  {
    if (c == 'E')
      cur++;
    else if (c == 'W')
      cur--;
    mx = max(mx, cur);
    mn = min(mn, cur);
  }

  string ans = string(mx + 1 - cur, 'E') + string(r2, 'S') + string(mx + 1, 'W');
  string ans2 = string(cur - mn + 1, 'W') + string(r2, 'S') + string(abs(mn - 1), 'E');
  if (ans.size() < ans2.size())
    return ans;
  return ans2;
}
int32_t main()
{
  string s;
  // cin >> s;
  s += 'N';
  for (int i = 0; i < 100000 / 10; i++)
  {
    s += "EEENWWW";
  }
  s += 'N';

  cout << solution(s) << endl;
  // cout << solution1(s);
  return 0;
}
