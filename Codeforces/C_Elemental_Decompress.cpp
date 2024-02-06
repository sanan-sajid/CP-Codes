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

        int n;
        cin >> n;
        vector<int> v(n);
        set<int> s1;
        set<int> s2;
        // map<int,int>mp;
        for (int i = 0; i < n; i++)
        {
            s1.insert(i + 1);
            s2.insert(i + 1);
            cin >> v[i];
        }
        vector<pair<int, int>> vp(n);
        for (int i = 0; i < n; i++)
        {
            vp[i].first = v[i];
            vp[i].second = i;
        }
        sort(all(v));
        sort(all(vp));
        vector<int> a(n);
        vector<int> b(n);
        bool flag = 1;
        for (int i = 0; i < n; i++)
        {
            if (s1.find(v[i]) != s1.end())
            {
                a[i] = v[i];

                s1.erase(v[i]);
            }
            else if (s2.find(v[i]) != s2.end())
            {
                b[i] = v[i];
                s2.erase(v[i]);
            }
            else
            {
                flag = 0;
                break;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (a[i] == 0)
            {

                a[i] = *s1.begin();
                s1.erase(a[i]);
            }
            if (b[i] == 0)
            {

                b[i] = *s2.begin();
                s2.erase(b[i]);
            }
        }

        // for (auto it : a)
        //     cout << it << " ";
        // cout << endl;
        // for (auto it : b)
        //     cout << it << " ";
        // for (auto it : vp)
        // {
        //     cout << it.first << " " << it.second << endl;
        // }
        vector<pair<int, pair<int, int>>> vpp(n);
        for (int i = 0; i < n; i++)
        {
            vpp[i].first = vp[i].second;
            vpp[i].second.first = a[i];
            vpp[i].second.second = b[i];
        }
        sort(all(vpp));

        for (int i = 0; i < n; i++)
        {
            if (max(a[i], b[i]) != v[i])
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            cout << "YES\n";
            for (auto it : vpp)
                cout << it.second.first << " ";
            cout << endl;
            for (auto it : vpp)
                cout << it.second.second << " ";
            cout << endl;
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}
