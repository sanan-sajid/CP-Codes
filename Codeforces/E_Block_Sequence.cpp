#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// VVI ITS FOR 0 BASED-INDEX NODES , IF NODES ARE FROM 1 THEN USE n+1
class DSU
{
private:
    vector<int> parent, size;

public:
    DSU(int n)
    {
        parent = vector<int>(n);
        size = vector<int>(n, 1);
        iota(begin(parent), end(parent), 0);
    }

    int getParent(int x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = getParent(parent[x]);
    }

    void join(int x, int y)
    {
        x = getParent(x);
        y = getParent(y);
        if (size[x] > size[y])
            swap(x, y);
        if (x == y)
            return;
        parent[x] = y;
        size[y] += size[x];
    }

    int getSize(int x)
    {
        return size[x] = size[getParent(x)];
    }
};
bool isNear(int i, int j, vector<vector<int>> &bombs)
{
    // i is detonating and we are checking if j will explode or not?
    int x1 = bombs[i][0];
    int y1 = bombs[i][1];
    int r1 = bombs[i][2];
    int x2 = bombs[j][0];
    int y2 = bombs[j][1];
    if (sqrt(((long long)(y2 - y1) * (y2 - y1) + (long long)(x2 - x1) * (x2 - x1))) <= r1 * 1.0)
        return 1;

    return 0;
}
int dfs(vector<vector<int>> &adjList, int node, vector<bool> &vis)
{
    vis[node] = 1;
    int res = 0;
    for (auto v : adjList[node])
    {
        if (!vis[v])
            res += dfs(adjList, v, vis);
    }
    return res + 1;
}
int maximumDetonation(vector<vector<int>> &bombs)
{
    int n = bombs.size();
    vector<vector<int>> adjList(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            if (isNear(i, j, bombs))
            {
                adjList[i].push_back(j);
            }
        }
    }
    int res = 0;
    for (int i = 0; i < n; i++)
    {
    vector<bool> vis(n, false);

        res = max(res, dfs(adjList, i, vis));
        
    }
    return res;
}

int main()
{

    return 0;
}
