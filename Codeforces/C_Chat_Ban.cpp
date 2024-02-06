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
bool helper(int idk, int k, int x)
{
    int sum = 0;
    int sum1 = 0;
    int idk1 = idk - 1;
    if (idk1 <= k)
    {
        sum1 = (idk1 * (idk1 + 1)) / 2;
    }
    else
    {
        sum1 = (k * (k + 1) / 2);
        int temp = idk1 - k;
        sum1 += temp * k - ((temp * (temp + 1)) / 2);
    }
    if (idk <= k)
    {
        sum = (idk * (idk + 1)) / 2;
    }
    else
    {
        sum = (k * (k + 1) / 2);
        int temp = idk - k;
        sum += temp * k - ((temp * (temp + 1)) / 2);
    }

    return (sum1 <= x && x <= sum);
}
// bool helper1(int idk,int k,int x){
// int s1=helper(idk)
// }
int32_t main()
{
    ll t = 1;
    cin >> t;
    while (t--)
    {
        int k, x;
        cin >> k >> x;
        int res = 0;
        int l = 0, r = 2 * k - 1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (helper(mid, k, x))
            {
                res = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        cout << r << endl;
    }
    return 0;
}
// k=1 ->*
// k=2 ->
//  *
//  **
//  *
