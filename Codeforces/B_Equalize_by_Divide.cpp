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
int32_t main()
{
    ll t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        bool flag = 1;
        for (int i = 0; i < n - 1; i++)
        {
            if (v[i] != v[i + 1])
            {
                flag = 0;
                break;
            }
        }
        //     if(flag==1){
        //         cout<<-1<<endl;
        // }
        bool flag1 = 0;
        for (auto it : v)
        {
            if (it == 1)
            {
                flag1 = 1;
                break;
            }
        }
        vector<pair<int, int>> res;
        vector<pair<int, int>> v1;
        if (flag == 1)
            cout << 0 << endl;
        else if (flag1)
            cout << -1 << endl;
        else
        {

            for (int i = 0; i < n; i++)
            {
                v1.push_back({v[i], i + 1});
            }

            for (int k = 0; k < 30 * n; k++)
            {
                bool flag = 1;
                for (int i = 0; i < n - 1; i++)
                {
                    if (v1[i].first != v1[i + 1].first)
                    {
                        flag = 0;
                        break;
                    }
                }
                if (flag == 1)
                    break;
                sort(all(v1));
                int mini = v1[0].first;
                for (int i = 0; i < n; i++)
                {
                    if (v1[i].first != mini)
                    {
                        v1[i].first = ceil((1.0 * v1[i].first) / mini);
                        res.push_back({v1[0].second, v1[i].second});
                    }
                }
            }
            cout << res.size() << endl;
            for (auto it : res)
            {
                cout << it.second << " " << it.first << endl;
            }
        }
    }
    return 0;
}
