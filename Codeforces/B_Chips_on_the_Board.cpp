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
/// ====================================BIT TRICKS==================================================
// TO CHECK IF iTH BIT IS SET OR NOT
// for (int j = 0; j < 31; j++)
//             {
//                 if ((v[i] & (1 << j)))
//                 {
//                     setBit[j]++;
//                 }
//             }
/// ====================================BIT TRICKS ENDS HERE==================================================
/// ====================================Some learning here==================================================

// 1.never erase anything from ds(map,set,vector ,etc )while iterating , store the elements in another ds which to be
//   deleted then run another loop and use erase fxn.

/// ====================================End==================================================
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

        int n;
        cin >> n;
        vector<int> v1(n);
        vector<int> v2(n);
        int sum1 = 0, sum2 = 0;
        int min1 = INT_MAX;
        int min2 = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            cin >> v1[i];
            sum1 += v1[i];
            min1 = min(min1, v1[i]);
        }
        for (int i = 0; i < n; i++)
        {
            cin >> v2[i];
            sum2 += v2[i];
            min2 = min(min2, v2[i]);
        }
        // int ans = INT_MAX;
        int ans = min(min1 * n + sum2, min2 * n + sum1);
        // ans = min(min2 * n + sum1, ans);
        cout << ans;

        cout << endl;
    }
    return 0;
}