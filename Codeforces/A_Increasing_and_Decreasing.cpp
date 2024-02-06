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
// n = unique(all(v)) - v.begin(); REMOVE DUPS AND IMP TO STORE NEW VALUE OF N SIZE OF ARRAY
int32_t main()
{
    ll t = 1;
    cin >> t;
    while (t--)
    {

        int x, y, n;
        cin >> x >> y >> n;
        vector<int> v(n);
        v[0] = y;
        v[n - 1] = x;
        int j = 1;
        for (int i = 1; i < n - 1; i++)
        {
            v[i] = v[i - 1] - i;
        }
        reverse(all(v));
        // for (auto it : v)
        //     cout << it << " ";
        // cout << endl;
        vector<int> b;
        for (int i = 0; i < n - 1; i++)
        {
            b.push_back(v[i + 1] - v[i]);
        }
        // for (auto it : b)
        //     cout << it << " ";
        bool flag = 1;
        for (int i = 0; i < n - 1; i++)
        {
            if (v[i + 1] - v[i] <= 0)
            {
                flag = 0;
                break;
            }
        }
        for (int i = 0; i < b.size() - 1; i++)
        {
            if (b[i + 1] - b[i] >= 0)
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            for (auto it : v)
                cout << it << " ";
        }
        else
            cout << -1;
        cout << endl;
    }
    return 0;
}
