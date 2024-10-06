#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
class DSU
{
private:
    vector<int> parent, size;

public:
    DSU(int n)
    {
        size.resize(n, 1);
        parent.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    int getParent(int x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = getParent(parent[x]);
    }
    int size(int x)
    {
        return size[x] = size[getParent(x)];
    }
    void join(int x, int y)
    {
        x = getParent(x);
        y = getParent(y);
        if (x == y)
            return;
        if (size[x] > size[y])
        {
            swap(x, y);
        }
        size[y] += size[x];
        parent[x] = y;
    }
};
int32_t main()
{

    return 0;
}
