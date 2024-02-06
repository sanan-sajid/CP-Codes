#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int M = 1e9 + 7;

bool isvalid(int row, int col, int n, int m)
{
    if (row >= 0 && row < n && col >= 0 && col < m)
        return true;
    return false;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<vector<char>> grid(n, vector<char>(m, 0));
    queue<pair<pair<int, int>, string>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char ch;
            cin >> ch;
            grid[i][j] = ch;
            if (ch == 'A')
            {
                string temp = "";
                q.push({{i, j}, temp});
                vis[i][j] = 1;
            }
        }
    }

    int dx[] = {0, 0, -1, 1};
    int dy[] = {-1, 1, 0, 0};
    unordered_map<int, char> mp;
    mp[0] = 'L';
    mp[1] = 'R';
    mp[2] = 'U';
    mp[3] = 'D';

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        int row = it.first.first;
        int col = it.first.second;
        string s = it.second;

        for (int k = 0; k < 4; k++)
        {
            int newrow = row + dx[k];
            int newcol = col + dy[k];
            string temp = s;
            temp.push_back(mp[k]);
            if (isvalid(newrow, newcol, n, m) && !vis[newrow][newcol] && grid[newrow][newcol] != '#')
            {
                if (grid[newrow][newcol] == 'B')
                {
                    cout << "YES" << endl;
                    cout << temp.length() << endl;
                    cout << temp << endl;
                    return;
                }
                else
                {
                    q.push({{newrow, newcol}, temp});
                    vis[newrow][newcol] = 1;
                }
            }
        }
    }

    cout << "NO" << endl;
}

int main()
{
    int t = 1;
    // cin >>t;
    while (t--)
    {
        solve();
    }
}