#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
class Node
{
public:
  int data;
  Node *next;
  Node(int data1, Node *next1)
  {
    data = data1;
    next = next1;
  }
  Node(int data1)
  {
    data = data1;
    next = nullptr;
  }
};
void printLL(Node *head)
{
  while (head != NULL)
  {
    cout << head->data << " ";
    head = head->next;
  }
}
int32_t main()
{
  int n = 5;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  int i = 1;

  Node *head = new Node(v[0]);
  Node *mover = head;
  while (i != n)
  {
    Node *temp = new Node(v[i]);
    mover->next = temp;
    i++;
    mover = temp;
  }
  printLL(head);

  return 0;
}
