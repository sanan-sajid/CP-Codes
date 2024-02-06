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

int main()
{
  int mid = 7, it = 8;
  int req = 0;
  for (int i = 0; i < 30; i++)
  {
    // cout << ((mid >> i) & 1) << endl;
    if (!((((mid >> i) & 1) & ((it >> i) & 1))) & ((mid >> i) & 1))
    {
      cout << i << endl;
      req += (1 << i);
    }
  }
  cout << req;
  return 0;
}
