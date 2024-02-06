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
int largestDivisor(int num)
{
    for (int i = num / 2; i >= 1; --i)
    {
        if (num % i == 0)
        {
            return i;
        }
    }
    return num; // The number itself is also its divisor
}
int smallestDivisor(int num)
{
    for (int i = 2; i <= num; ++i)
    {
        if (num % i == 0)
        {
            return i;
        }
    }
    return num; // The number itself is also its divisor
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

        int n;
        cin >> n;
        vector<int> ans;
        ans.push_back(n);
        if (log2(n) == ceil(log2(n)))
        {

            while (n != 1)
            {
                n = n / 2;
                ans.push_back(n);
            }
        }
        else
        {
            int i = 0;
            while (log2(n) != ceil(log2(n)))
            {
                // 1101
                if (n & (1 << i))
                {

                    n = n - (1 << i);
                    ans.push_back(n);
                }
                i++;
                // cout << n << endl;
            }
            while (n != 1)
            {
                n = n / 2;
                ans.push_back(n);
            }
        }
        cout << ans.size() << endl;
        for (auto it : ans)
            cout << it << " ";

        cout << endl;
    }
    return 0;
}
