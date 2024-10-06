#include <iostream>

using namespace std;

int countCriticalEvents(int data[], int n)
{
  int pxor[n]; // Prefix XOR array
  pxor[0] = 0; // XOR of an empty set is 0

  // Build prefix XOR array
  for (int i = 1; i < n; i++)
  {
    pxor[i] = pxor[i - 1] ^ data[i];
  }

  int count = 0;
  // Iterate through triplets
  for (int x = 0; x < n; x++)
  {
    for (int y = x; y < n; y++)
    {
      for (int z = y; z < n; z++)
      {
        int f_xy = pxor[y] ^ pxor[x - 1]; // XOR from x to y
        int f_yz = pxor[z] ^ pxor[y - 1]; // XOR from y to z
        if (f_xy < f_yz)
        {
          count++;
        }
      }
    }
  }

  return count;
}

int main()
{
  int n;
  cin >> n;

  int data[n];
  for (int i = 0; i < n; i++)
  {
    cin >> data[i];
  }

  int critical_events = countCriticalEvents(data, n);
  cout <<critical_events << endl;

  return 0;
}
