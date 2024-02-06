#include <bits/stdc++.h>
using namespace std;

long long minCost(vector<int> &basket1, vector<int> &basket2)
{
    int n = basket1.size();
    unordered_map<int, int> mp1;
    unordered_map<int, int> mp2;
    for (auto it : basket1)
        mp1[it]++;
    for (auto it : basket2)
        mp2[it]++;
    for (auto it : mp1)
    {

        if ((mp1[it.first] + mp2[it.first] % 2) == 1)
        {
            return -1;
        }
    }
    for (auto it : mp2)
    {
        if ((mp1[it.first] + mp2[it.first] % 2) == 1)
            return -1;
    }
    sort(basket1.begin(), basket1.end());
    sort(basket2.begin(), basket2.end());
    int mini = min(basket1[0], basket2[0]);
    long long res = 2 * mini;
    vector<int> a, b;
    for (auto it : mp1)
    {

        for (int j = 0; j < max(0, mp1[it.first] - mp2[it.first]); j++)
        {
            a.push_back(it.first);
        }
    }
    for (auto it : mp2)
    {

        for (int j = 0; j < max(0, mp2[it.first] - mp1[it.first]); j++)
        {

            b.push_back(it.first);
        }
    }
    // for (auto it : a)
    //     cout << it << " ";
    // cout << endl;
    // for (auto it : b)
    //     cout << it << " ";
    for (int i = 0; i < (a.size() + 1) / 2; i++)
    {
        long long temp = min(a[i], b[n - 1 - i]);
        res = min(res, temp);
    }
    return res;
}

int main()
{
    vector<int> a = {1, 1, 2, 4};
    vector<int> b = {2, 2, 2, 4};
    cout << minCost(a, b);
    return 0;
}
