#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void swapPairs(vector<int> &vec)
{
  if (vec.size() == 4)
  {
    swap(vec[0], vec[2]);
    swap(vec[1], vec[3]);
  }
}

void printVector(const vector<vector<int>> &v)
{
  for (const auto &inner : v)
  {
    for (int num : inner)
    {
      cout << num << " ";
    }
    cout << "| ";
  }
  cout << endl;
}

int main()
{
  vector<vector<int>> v = {{1, 3, 2, 1}, {0, 2, 0, 0}, {3, 0, 2, 0}};
  int count = 0;

  cout << "Original vector:" << endl;
  printVector(v);

  do
  {
    cout << "\nPermutation " << ++count << ":" << endl;
    printVector(v);

    vector<vector<int>> swapped_v = v;
    for (auto &vec : swapped_v)
    {
      swapPairs(vec);
    }

    cout << "Swapped version:" << endl;
    printVector(swapped_v);

  } while (next_permutation(v.begin(), v.end()));

  cout << "\nTotal number of permutations (including swapped versions): " << count * 2 << endl;

  return 0;
}