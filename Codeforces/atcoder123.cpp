#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD 1000000007
#define vi vector<int>
#define vpi vector<pair<int, int>>

int rec(int level, string &s, int n, char last, vector < vector <int >>&dp) {
    if (level == n) return 0;
    int lastNum= last == 'R' ? 0 : (last == 'P' ? 1 : 2);
    if (dp[level][lastNum] != -1) {
        return dp[level][lastNum];
    }
    int ans= 0;
    int ans1=0, ans2=0;
    if (s[level] == 'R') {
        // try to win
        if (last == 'P') ans1= INT_MIN;
        else ans1 = 1+rec(level+1, s, n, 'P', dp);
    }
    if (s[level] == 'P') {
        // try to win
        if (last == 'S') ans1= INT_MIN;
        else ans1 = 1+rec(level+1, s, n, 'S', dp);
    }
    if (s[level] == 'S') {
        // try to win
        if (last == 'R') ans1= INT_MIN;
        else ans1 = 1+rec(level+1, s, n, 'R', dp);
    }

    // try to draw
    if (last == s[level]) ans2= INT_MIN;
    else ans2= rec(level+1, s, n, s[level], dp);
    ans = max(ans1, ans2);
    return dp[level][lastNum]= ans;
}

void solve() {
    
    int n; cin >> n;
    string s; cin >> s;
    vector < vector <int >>dp(n+1, vector <int >(3, -1));
    cout << rec (0, s, n, 'A', dp)<< endl;
}


signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    
    int t=1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
