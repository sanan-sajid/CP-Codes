#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int n, m, y;
bool valid(int i, int j)
{
  if (i < 0 || j < 0 || i >= n || j >= m)
    return false;
  return true;
}

void bfs(vector<vector<int>> &v, int sea_level, vector<vector<bool>> &sunk)
{
  queue<pair<int, int>> q;
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < m; ++j)
    {
      if ((i == 0 || i == n - 1 || j == 0 || j == m - 1) && v[i][j] <= sea_level && !sunk[i][j])
      {
        q.push({i, j});
        sunk[i][j] = true;
      }
    }
  }

  while (!q.empty())
  {
    auto [x, y] = q.front();
    q.pop();

    for (int d = 0; d < 4; ++d)
    {
      int nx = x + dx[d], ny = y + dy[d];
      if (valid(nx, ny) && v[nx][ny] <= sea_level && !sunk[nx][ny])
      {
        sunk[nx][ny] = true;
        q.push({nx, ny});
      }
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m >> y;
  vector<vector<int>> v(n, vector<int>(m));

  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < m; ++j)
    {
      cin >> v[i][j];
    }
  }

  for (int year = 1; year <= y; ++year)
  {
    vector<vector<bool>> sunk(n, vector<bool>(m, false));
    bfs(v, year, sunk);

    int remaining_land = 0;
    for (int i = 0; i < n; ++i)
    {
      for (int j = 0; j < m; ++j)
      {
        if (!sunk[i][j])
        {
          ++remaining_land;
        }
      }
    }

    cout << remaining_land << endl;
  }

  return 0;
}
