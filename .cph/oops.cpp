#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
  int val;         // value at node
  TreeNode *left;  // pointer to left node
  TreeNode *right; // pointer to right node

  // default constructor
  TreeNode()
  {
    left = nullptr;  // point towards null
    right = nullptr; // point towards null
    val = 0;         // set data to a default value (say 0)
  }

  TreeNode(int x)
  {
    left = nullptr;  // point towards null
    right = nullptr; // point towards null
    val = x;
  }

  TreeNode(int x, TreeNode *l, TreeNode *r)
  {
    left = l;  // point towards left
    right = r; // point towards right
    val = x;
  }
};

void makeBST(int i, vector<int> &v, TreeNode *root)
{
  TreeNode *parent = NULL;
  while (root != NULL)
  {
    if (root->val > v[i])
    {
      parent = root;
      root = root->left;
    }
    else
    {
      parent = root;
      root = root->right;
    }
  }
  if (parent->val > v[i])
  {
    parent->left = new TreeNode(v[i]);
  }
  else
  {
    parent->right = new TreeNode(v[i]);
  }
}
void collectLevels(TreeNode *root, std::vector<std::vector<TreeNode *>> &levels)
{
  if (root == nullptr)
    return;

  std::queue<TreeNode *> q;
  q.push(root);

  while (!q.empty())
  {
    int size = q.size();
    std::vector<TreeNode *> level;

    for (int i = 0; i < size; ++i)
    {
      TreeNode *node = q.front();
      q.pop();
      level.push_back(node);

      if (node != nullptr)
      {
        q.push(node->left);
        q.push(node->right);
      }
      else
      {
        q.push(nullptr);
        q.push(nullptr);
      }
    }

    // Check if the entire level is empty (all nullptrs)
    bool allNull = true;
    for (TreeNode *node : level)
    {
      if (node != nullptr)
      {
        allNull = false;
        break;
      }
    }

    if (allNull)
      break;

    levels.push_back(level);
  }
}

void printBST(TreeNode *root)
{
  std::vector<std::vector<TreeNode *>> levels;
  collectLevels(root, levels);

  int maxLevel = levels.size();
  int width = (1 << maxLevel) - 1; // Width of the bottom level

  for (int i = 0; i < levels.size(); ++i)
  {
    int levelWidth = (1 << (maxLevel - i - 1)) - 1;
    int spacing = (1 << (maxLevel - i)) - 1;

    for (int j = 0; j < levels[i].size(); ++j)
    {
      if (j > 0)
        std::cout << std::setw(spacing) << " ";

      if (levels[i][j] != nullptr)
        std::cout << std::setw(levelWidth + 1) << levels[i][j]->val;
      else
        std::cout << std::setw(levelWidth + 1) << " ";
    }
    std::cout << std::endl;
  }
}

int main()
{
  std::vector<int> values = {3, 2, 1, 5, 67};
  TreeNode *root = new TreeNode(values[0]);

  for (int i = 1; i < values.size(); ++i)
  {
    makeBST(i, values, root);
  }
  printBST(root);

  return 0;
}