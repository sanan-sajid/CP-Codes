#include <bits/stdc++.h>
#define mod 1000000007
#define LL long long int
using namespace std;
int main()
{
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    LL T;
    T = 1;
    while (T--)
    {
        LL N;
        cin >> N;
        vector<LL> arr(N);
        for (auto &it : arr)
            cin >> it;
        vector<vector<LL>> d(N + 1, vector<LL>(N + 1, -1));
        function<LL(LL, LL)> dp = [&](LL index, LL left)
        {
            // WHAT GREATEST SUM I CAN MAKE
            // WHAT MAX  SUM IF I SKIP THIS ELEMENT
            if (index < 0 and left > 0)
            {
                return (LL)INT_MIN;
            }
            if (index < 0 and left == 0)
            {
                return 0LL;
            }
            if (d[index][left] != -1)
            {
                return d[index][left];
            }
            if (left > 0)
            {

                LL ifIskip = dp(index - 1, left);
                LL ifIchoose = dp(index - 1, left - 1) + arr[index];

                if (ifIchoose < 0 && ifIskip < 0)
                {
                    return d[index][left] = (LL)INT_MIN;
                }
                else if (ifIskip < 0)
                {
                    return d[index][left] = ifIchoose;
                }
                else if (ifIchoose < 0)
                {
                    return d[index][left] = ifIskip;
                }
                return d[index][left] = max(ifIskip, ifIchoose);
            }
            else
            {
                return d[index][left] = dp(index - 1, left);
            }
        };
        LL ans = INT_MIN;
        for (LL i = 0; i <= N; i++)
        {
            cout << dp(N - 1, i) << " ";

            if (dp(N - 1, i) >= 0)
            {
                ans = max(ans, i);
            }
        }
        for (int i = 0; i <= N; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                cout << dp(i, j) << " ";
            }
            cout << endl;
        }
        // cout << ans << endl;
    }
}