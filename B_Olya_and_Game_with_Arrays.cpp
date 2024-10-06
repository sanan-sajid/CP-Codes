#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
int n;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
bool isValid(int i, int j)
{
  if (i < 0 || j < 0 || i >= n || j >= n)
    return 0;
  return 1;
}
int maximumSafenessFactor(vector<vector<int>> &grid)
{
  n = grid.size();
  vector<vector<int>> dis(n, vector<int>(n, 1e9));
  queue<pair<int, pair<int, int>>> q; // dis,x,y
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (grid[i][j] == 1)
      {
        q.push({0, {i, j}});
        dis[i][j] = 0;
      }
    }
  }
  while (!q.empty())
  {
    auto it = q.front();
    q.pop();
    int dist = it.first;
    int x = it.second.first;
    int y = it.second.second;

    dis[x][y] = min(dist, dis[x][y]);
    for (int a = 0; a < 4; a++)
    {
      if (isValid(x + dx[a], dy[a] + y) && dis[x + dx[a]][y + dy[a]] == 1e9)
      {
        q.push({dist + 1, {x + dx[a], dy[a] + y}});
      }
    }
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << dis[i][j] << " ";
    }
    cout << endl;
  }
  int res = dis[0][0];
  int x = 0, y = 0;
  while (x != n - 1 && y != n - 1)
  {
    cout << x << " " << y << " " << n - 1 << endl;
    // only down
    if (x == n - 1)
    {
      y++;
    }
    // only right
    else if (y == n - 1)
    {
      x++;
    }
    // else both
    else if (dis[x + 1][y] >= dis[x][y + 1])
    {
      x++;
    }
    else
    {
      y++;
    }
    res = min(res, dis[x][y]);
  }
  return res;
}
int32_t main()
{

  return 0;
}
