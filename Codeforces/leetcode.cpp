#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int a[N];
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n, q;
    cin >> n >> q;
    map<int, vector<int>> id;
    id[0].push_back(0);
    for (int i = 1; i <= n; i++)
    {
      cin >> a[i];
      a[i] ^= a[i - 1];
      id[a[i]].push_back(i);
    }
    // for (auto it : a)
    //   cout << it << " ";
    while (q--)
    {
      int l, r;
      cin >> l >> r;
      if (a[r] == a[l - 1])
      {
        cout << "YES\n";
        continue;
      }
      int pL = *--lower_bound(id[a[l - 1]].begin(), id[a[l - 1]].end(), r);
      int pR = *lower_bound(id[a[r]].begin(), id[a[r]].end(), l);
      cout << pL << " " << pR << endl;
      cout << (pL > pR ? "YES\n" : "NO\n");
    }
    if (t)
      cout << "\n";
  }
}