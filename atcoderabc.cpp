#include <iostream>
#include <vector>
using namespace std;

// Function to find the largest subarray having an equal number of 0's and 1's
void findLargestSubarray(int nums[], int n)
{
  // Transform the binary array to handle 0 as -1
  for (int i = 0; i < n; ++i)
  {
    if (nums[i] == 0)
    {
      nums[i] = -1;
    }
  }

  // Create an array to store the first occurrence of each sum
  vector<int> first_occurrence(2 * n + 1, -1);

  // Initialize variables
  int sum = 0;
  int len = 0;
  int start_index = -1;

  // Handle the case when the sum is zero at the start
  first_occurrence[n] = -1;

  // Traverse through the given array
  for (int i = 0; i < n; ++i)
  {
    sum += nums[i];

    // If the sum has been seen before, calculate the length of the subarray
    if (first_occurrence[sum + n] != -1)
    {
      if (i - first_occurrence[sum + n] > len)
      {
        len = i - first_occurrence[sum + n];
        start_index = first_occurrence[sum + n] + 1;
      }
    }
    else
    {
      // Store the first occurrence of the sum
      first_occurrence[sum + n] = i;
    }
  }

  // Print the subarray if present
  if (start_index != -1)
  {
    cout << "[" << start_index << ", " << start_index + len - 1 << "]";
  }
  else
  {
    cout << "No subarray exists";
  }
}

int main()
{
  int nums[] = {0, 0, 1, 0, 1, 0, 0};
  int n = sizeof(nums) / sizeof(nums[0]);

  findLargestSubarray(nums, n);

  return 0;
}
