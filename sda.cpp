#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
int ans = 1e9;
int sum = 0;

void findCost(int r, int p, vector<int> &arr, vector<vector<int>> &edges)
{
  int i, cur;
  for (i = 0; i < edges[r].size(); i++)
  {
    cur = edges[r][i];
    if (cur == p)
      continue;
    findCost(cur, r, arr, edges);
    arr[r] += arr[cur];
  }

  int t1 = arr[r];
  int t2 = sum - t1;

  if (abs(t2 - t1) < ans)
  {
    ans = abs(t2 - t1);
  }
}

int f(int n, vector<int> &a, vector<int> &b)
{
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    arr[i] = i + 1;

  vector<vector<int>> adj(n);
  for (int i = 0; i < n - 1; i++)
  {
    adj[a[i]].push_back(b[i]);
    adj[b[i]].push_back(a[i]);
  }

  sum = (n * (n + 1)) / 2;
  findCost(0, -1, arr, adj);

  return ans;
}

int32_t main()
{
  int n;
  cin >> n;
  vector<int> a(n - 1), b(n - 1);
  for (int i = 0; i < n - 1; i++)
  {
    cin >> a[i];
    a[i]--;
  }
  for (int i = 0; i < n - 1; i++)
  {
    cin >> b[i];
    b[i]--;
  }
  cout << f(n, a, b) << endl;

  return 0;
}
