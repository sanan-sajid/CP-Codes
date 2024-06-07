#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;

struct Trienode
{
  Trienode *childNode[26];
  bool wordEnd;
  Trienode()
  {
    wordEnd = false;
    for (int i = 0; i < 26; i++)
      childNode[i] = NULL;
  }
};
void insert(Trienode *root, string s)
{
  Trienode *currentNode = root;
  for (auto it : s)
  {
    if (currentNode->childNode[it - 'a'] == NULL)
    {
      Trienode *newNode = new Trienode();
      currentNode->childNode[it - 'a'] = newNode;
    }
    currentNode = currentNode->childNode[it - 'a'];
  }
  currentNode->wordEnd = true;
}
bool search(Trienode *root, string s)
{
  Trienode *currentNode = root;
  for (auto it : s)
  {
    if (currentNode->childNode[it - 'a'] == NULL)
    {
      return false;
    }
    else
    {
      currentNode = currentNode->childNode[it - 'a'];
    }
  }
  return currentNode->wordEnd == 1;
}
string f(Trienode *root, string s)
{
  string res;
  Trienode *currentNode = root;
  for (auto it : s)
  {
    if (currentNode->wordEnd == true)
      return res;
    res += it;
    if (currentNode->childNode[it - 'a'] == NULL)
    {
      return s;
    }
    else
    {
      currentNode = currentNode->childNode[it - 'a'];
    }
  }
  if (currentNode->wordEnd == true)
    return res;
  return s;
}
int32_t main()
{
  Trienode *root = new Trienode();
  int n;
  cin >> n;
  vector<string> inputStrings(n);
  for (int i = 0; i < n; i++)
    cin >> inputStrings[i];
  for (auto it : inputStrings)
    insert(root, it);
  string temp;
  cin >> temp;
  cout << f(root, temp);
  return 0;
}
