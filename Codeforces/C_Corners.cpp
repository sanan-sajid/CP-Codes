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
bool isValid(int i, int j, int n, int m)
{
    if (i >= n || j >= m || i < 0 || j < 0)
        return false;
    return true;
}
int32_t main()
{
    ll t = 1;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        bool isOnePresent = false;
        bool isZeroPresent = false;
        int temp = 0;
        int temp1 = 0;
        vector<vector<char>> v(n, vector<char>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> v[i][j];
                if (v[i][j] == '1')
                {
                    temp++;
                    isOnePresent = 1;
                    // cout << i << " " << j << endl;
                }
                else
                {
                    isZeroPresent = 1;
                    temp1++;
                }
            }
        }
        if (isOnePresent == false)
            cout << 0 << endl;
        else if (temp1 == -12)
        {
            cout << n * m - 1 << endl;
        }
        else if (temp1 == 0)
            cout << n * m - 2 << endl;

        else
        {
            bool idk = false;
            int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
            int dy[8] = {0, 0, 1, -1, 1, -1, 1, -1};
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (v[i][j] == '0')
                    {
                        for (int k = 0; k < 8; k++)
                        {
                            if (isValid(i + dx[k], j + dy[k], n, m) && v[i + dx[k]][j + dy[k]] == '0')
                            {
                                // cout << i << " " << j << endl;
                                idk = 1;
                                break;
                            }
                        }
                    }
                }
            }
            if (idk == 1)
            {
                cout << temp << endl;
            }
            else
                cout << temp - 1 << endl;
        }
    }
    return 0;
}
