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

        int n, k;
        cin >> n >> k;
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            mp[x]++;
        }
        bool flag = 0;
        for (auto it : mp)
        {
            if (it.second >= k)
                flag = 1;
        }
        // cout << flag;

        if (flag == 0)
        {
            cout << -1 << endl;
        }
        else
        {
            vector<int> idk;
            // for(auto it=mp.begin();it!=mp.end();it++){

            // }
            for (auto it : mp)
            {

                if (it.second < k)
                {
                    // mp.erase(it.first);
                    idk.push_back(it.first);
                }
            }
            for (auto it : idk)
            {
                mp.erase(it);
            }
            vector<int> v;
            for (auto it : mp)
            {
                v.push_back(it.first);
            }

            int ans = 0;
            int i = 0, j = 0;
            int l, r;
            while (j < v.size())
            {
                while (j + 1 < v.size() && v[j + 1] - 1 == v[j])
                {
                    j++;
                }

                if (ans < j - i + 1)
                {
                    ans = j - i + 1;
                    l = v[i];
                    r = v[j];
                }
                i = j + 1;
                j = j + 1;
            }
            cout << l << " " << r << endl;
        }
    }
    return 0;
}