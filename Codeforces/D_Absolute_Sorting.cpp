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

string largestGoodInteger(string num)
{

    int n = num.size();
    int res = -1;
    for (int i = 0; i + 2 <= n - 1; i++)
    {
        if (num[i] == num[i + 1] && num[i + 1] == num[i + 2])
        {
            res = max(res, num[i] - '0');
        }
    }
    string s = "";
    if (res != -1)
    {
        s += (res + '0');
        s += (res + '0');
        s += (res + '0');
        
    }

    return s;
}

int main()
{

    return 0;
}
