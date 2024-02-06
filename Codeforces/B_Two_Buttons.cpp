//      Coded By: Sahil Kumar        //

#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;

vector<int> dp;
vector<int> v;

int fun(int i)
{
    if (i == v.size())
    {
        return 0;
    }
    if (i > v.size())
    {
        return LLONG_MAX;
    }

    if (dp[i] != -1)
        return dp[i];

    dp[i] = min(fun(v[i] + i + 1), 1 + fun(i + 1));

    return dp[i];
}

void skcode()
{
    int n;
    cin >> n;
    v.clear();
    v.resize(n);
    dp.clear();
    dp.resize(n, -1);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    cout << fun(0);
}

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        skcode();
    }
    return 0;
}
