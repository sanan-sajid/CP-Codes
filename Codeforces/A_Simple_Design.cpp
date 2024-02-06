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
int f(vector<int> &nums, int k, int index)
{

    int a = INT_MIN;
    int b = INT_MIN;
    if (nums[index] >= 0)
    {
        a = nums[index];
        for (int i = 1; i <= k; i++)
            a = a + f(nums, k, index + i);
    }
    else
    {

        int notTaken = f(nums, k, index + 1);
        int taken = nums[index];
        for (int i = 1; i <= k; i++)
            taken = taken + f(nums, k, index + i);
        b = max(taken, notTaken);
    }
    return max(a, b);
}
int constrainedSubsetSum(vector<int> &nums, int k)
{
    return f(nums,k,0);
}

int main()
{

    return 0;
}
