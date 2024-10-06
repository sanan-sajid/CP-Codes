#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to compute nCr (binomial coefficient)
long long binomialCoefficient(int n, int r)
{
  if (r > n)
    return 0;
  if (r == 0 || r == n)
    return 1;
  r = min(r, n - r); // Take advantage of symmetry
  long long result = 1;
  for (int i = 0; i < r; ++i)
  {
    result *= (n - i);
    result /= (i + 1);
  }
  return result;
}

// Function to compute the number of ways to visit houses with constraints
long long countWays(int N, int C, int V)
{
  if (V > C)
    return 0; // Impossible to visit more than C houses in a block of C

  // Total number of ways to choose houses
  long long totalWays = (1LL << N); // 2^N

  // Count the number of invalid ways
  long long invalidWays = 0;

  for (int k = 0; k < C; ++k)
  {
    long long invalidPerBlock = binomialCoefficient(C, k);
    long long blocksWithInvalid = (N - C + 1) * invalidPerBlock;
    if (k < V)
    {
      invalidWays += blocksWithInvalid;
    }
  }

  // Correctly apply inclusion-exclusion principle
  long long result = totalWays - invalidWays;

  return result;
}

int main()
{
  int N, C, V;
  // cout << "Enter the total number of houses (N): ";
  cin >> N;
  // cout << "Enter the length of consecutive houses (C): ";
  cin >> C;
  // cout << "Enter the minimum number of houses to visit in each block (V): ";
  cin >> V;

  if (C > N)
  {
    cout << "Invalid input: C cannot be greater than N." << endl;
    return 1;
  }

  long long result = countWays(N, C, V);
  cout << "Number of ways to visit the houses: " << result << endl;

  return 0;
}