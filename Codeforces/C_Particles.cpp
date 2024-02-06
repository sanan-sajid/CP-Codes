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

        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        int mini = n;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        vector<int> temp = v;
        sort(all(temp));
        for (int i = 0; i < n; i++)
        {

            if (temp[i] != i)
            {
                // cout << temp[i] << " " << i << endl;
                mini = i;
                break;
            }
        }
        vector<int> idk(n);
        idk[0] = mini;
        for (int i = 0; i < n - 1; i++)
        {
            idk[i + 1] = v[i];
        }
        idk.push_back(n);
        // for (auto it : idk)
        //     cout << it << " ";
        // k--;
        // k = n % k;
        // cout << " val of k " << k << endl;
        k--;
        k = (n + 1 - (k % (n + 1))) % (n + 1);
        if (k == 0)
        {
            for (int i = 0; i < n; i++)
                cout << idk[i] << " ";
        }
        else
        {
            // cout << "k val is " << k << endl;
            for (int i = k; i < n + 1; i++)
            {
                cout << idk[i] << " ";
            }
            for (int i = 0; i < k - 1; i++)
            {
                cout << idk[i] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
