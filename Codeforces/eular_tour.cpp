#include <vector>
#include <iostream>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr, right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
  int CountNodes(TreeNode *root)
  {
    if (!root)
      return 0;
    return 1 + CountNodes(root->left) + CountNodes(root->right);
  }

  void dfs(vector<int> &depth, TreeNode *root, int temp)
  {
    if (!root)
      return;
    depth[root->val] = temp;
    if (root->left)
      dfs(depth, root->left, temp + 1);
    if (root->right)
      dfs(depth, root->right, temp + 1);
  }

  vector<int> st, ed;
  void EulerTour(TreeNode *root, int &ind)
  {
    if (!root)
      return;
    st[root->val] = ind++;
    if (root->left)
      EulerTour(root->left, ind);
    if (root->right)
      EulerTour(root->right, ind);
    ed[root->val] = ind++;
  }

  vector<int> treeQueries(TreeNode *root, vector<int> &queries)
  {
    int n = CountNodes(root);
    int temp = 0;
    st.resize(n + 1, 0);
    ed.resize(n + 1, 0);
    vector<int> depth(n + 1);
    int ind = 1;
    EulerTour(root, ind);
    dfs(depth, root, temp);

    for (auto it : depth)
      cout << it << " ";
    cout << endl;
    for (auto it : st)
      cout << it << " ";
    cout << endl;
    for (auto it : ed)
      cout << it << " ";
    cout << endl;

    vector<int> res;
    return res;
  }
};
