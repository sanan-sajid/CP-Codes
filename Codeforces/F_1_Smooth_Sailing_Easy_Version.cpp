#include <bits/stdc++.h>
using namespace std;
void rearrange(vector<int> &a, int n)
{
  int next_to_place = 0;
  for (int i = 0; i < n; i++)
  {
    if (a[i] < 0)
    {
      std::swap(a[i], a[next_to_place++]);
    }
  }
  for (int i = next_to_place; i < n; i++)
  {
    if (a[i] == 0)
    {
      std::swap(a[i], a[next_to_place++]);
    }
  }
}

int main()
{
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  rearrange(v, n);
  for (int i = 0; i < n; i++)
    cout << v[i] << " ";

  return 0;
}
