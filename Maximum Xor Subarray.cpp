#include <bits/stdc++.h>
using namespace std;
#define INT_SIZE 32
struct TrieNode
{
  int value; // Only used in leaf nodes
  TrieNode *arr[2];
};

// Utility function to create a Trie node
TrieNode *newNode()
{
  TrieNode *temp = new TrieNode;
  temp->value = 0;
  temp->arr[0] = temp->arr[1] = NULL;
  return temp;
}

// Inserts pre_xor to trie with given root
void insert(TrieNode *root, int pre_xor)
{
  TrieNode *temp = root;

  // Start from the msb, insert all bits of
  // pre_xor into Trie
  for (int i = INT_SIZE - 1; i >= 0; i--)
  {
    // Find current bit in given prefix
    bool val = pre_xor & (1 << i);

    // Create a new node if needed
    if (temp->arr[val] == NULL)
      temp->arr[val] = newNode();

    temp = temp->arr[val];
  }

  // Store value at leaf node
  temp->value = pre_xor;
}

// Finds the maximum XOR ending with last number in
// prefix XOR 'pre_xor' and returns the XOR of this maximum
// with pre_xor which is maximum XOR ending with last element
// of pre_xor.
int query(TrieNode *root, int pre_xor)
{
  TrieNode *temp = root;
  for (int i = INT_SIZE - 1; i >= 0; i--)
  {
    // Find current bit in given prefix
    bool val = pre_xor & (1 << i);

    // Traverse Trie, first look for a
    // prefix that has opposite bit
    if (temp->arr[1 - val] != NULL)
      temp = temp->arr[1 - val];

    // If there is no prefix with opposite
    // bit, then look for same bit.
    else if (temp->arr[val] != NULL)
      temp = temp->arr[val];
  }
  return pre_xor ^ (temp->value);
}

int main()
{
  int n;
  cin >> n;
  vector<int> v(n);
  // for (int i = 0; i < n; i++)
  //   cin >> v[i];
  TrieNode *root = newNode();
  insert(root, 0);
  int temp = 0, res = 0;
  ;
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    temp = temp ^ x;
    insert(root, temp);
    res = max(res, query(root, temp));
  }
  cout << res;

  return 0;
}
