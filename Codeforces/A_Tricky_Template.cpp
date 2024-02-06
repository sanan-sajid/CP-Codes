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
void helper(vector<string> &res, string s, int open, int close, int sum)
{
  if (sum < 0)
    return;
  if (open == 0 && close == 0)
  {
    res.push_back(s);
    return;
  }
  s.push_back('(');
  helper(res, s, open - 1, close, sum + 1);
  s.pop_back();
  s.push_back(')');
  helper(res, s, open, close - 1, sum - 1);
  s.pop_back();
}
vector<string> generateParenthesis(int n)
{
  vector<string> res;
  string temp;
  helper(res, temp, n, n, 0);
  return res;
}

int main()
{

  return 0;
}
