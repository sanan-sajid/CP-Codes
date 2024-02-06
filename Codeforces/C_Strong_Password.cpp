#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(v) v.begin(), v.end()
#define vi vector<int>
typedef long long ll;
const int n1 = 1e9 + 7;

void primeFactors(int n, vector<int> &v)
{
    while (n % 2 == 0)
    {
        v.push_back(2);
        n = n / 2;
    }
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            v.push_back(i);
            n = n / i;
        }
    }
    if (n > 2)
        v.push_back(n);
}
int power(int x, int y, int p = n1)
{
    unsigned long long res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

int sz = 1e6 + 5;
bool PrimeSieve[1000005]; // 1e6+5
void buildSieve()
{
    for (int i = 2; i <= sz; i++)
        PrimeSieve[i] = 1;
    PrimeSieve[0] = 0; //
    PrimeSieve[1] = 0; // 1 is neither prime nor composite
    for (int i = 2; i < sz; i++)
    {
        if (PrimeSieve[i] == 0)
            continue; // the current number itself is composite
        for (int j = 2; j * i < sz; j++)
        {
            PrimeSieve[i * j] = 0;
        }
    }
}

bool isPrime(int n)
{
    // O(sqrt(N))
    if (n == 1)
        return 0;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}
/// ====================================PRIME utility ENDS here==================================================
// upper_bound(a.begin(),a.end(),x)-a.begin(); returns index ->arr[ind] > x
// lower_bound(a.begin(),a.end(),x)-a.begin(); returns index ->arr[ind] >= x
// MUST SORT THE ARRAY FIRST!! BEFORE USING UNIQUE
// n = unique(all(v)) - v.begin(); REMOVE DUPS AND IMP TO STORE NEW VALUE OF N SIZE OF ARRAY
int32_t main()
{
    ll t = 1;
    cin >> t;
    while (t--)
    {

        string s;
        cin >> s;
        int m;
        cin >> m;

        string l, r;
        cin >> l >> r;
        vector<vector<int>> v(10);
        for (int i = 0; i < s.size(); i++)
        {
            v[s[i] - '0'].push_back(i);
        }

        for (int i = 0; i < 10; i++)
        {
            v[i].push_back(s.size());
        }
        bool flag = 1;
        int ind = -1;

        for (int i = 0; i < m; i++)
        {
            int li = l[i] - '0';
            int ri = r[i] - '0';
            int newInd = 0;
            if (flag == 0)
            {
                break;
            }
            for (int j = li; j <= ri; j++)
            {
                int x = upper_bound(v[j].begin(), v[j].end(), ind) - v[j].begin();
                if (v[j][x] == s.size())
                {
                    flag = 0;
                    break;
                }
                else
                {
                    newInd = max(newInd, v[j][x]);
                }
            }
            ind = newInd;
        }
        if (!flag)
            cout << "YES";
        else
            cout << "NO";

        cout << endl;
    }
    return 0;
}
