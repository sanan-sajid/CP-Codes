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

        int a, b;
        cin >> a >> b;
        map<int, int> mp;
        for (int i = 0; i < b; i++)
        {
            int x, y;
            cin >> x >> y;
            mp[x]++;
            mp[y]++;
        }
        map<int, int> mp1;
        for (auto it : mp)
        {
            mp1[it.second]++;
        }

        // int res1 = 0;
        // int res2 = 0;

        // set<int> st;
        for (auto it : mp)
        {
            // st.insert(it.second);
            // cout << it.first << " " << it.second << endl;
        }
        // cout << endl;
        vector<int> v;

        for (auto it : mp1)
        {
            v.push_back(it.second);
            // st.insert(it.second);
            // cout << it.first << " " << it.second << endl;
        }
        sort(all(v));
        reverse(all(v));
        if (v.size() == 3)
            cout << v[1] << " " << v[0] / v[1] << endl;
        else
        {
            cout << (v[1] - 1) << " " << (v[0]) / (v[1] - 1) << endl;
        }
        // for (auto it : mp)
        // {
        //     if (it.second == *st.begin())
        //         res1++;
        //     if (it.second == *prev(st.end()))
        //         res2++;
        // }

        // cout << res2 << " " << res1 / res2;

        // cout << endl;
    }
    return 0;
}
