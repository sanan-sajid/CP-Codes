#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int sum = 0;
    vector<int> arr = {5, 9, 7, 6};
    int n = arr.size();

    for (int i = 0; i < 32; i++)
    {
        // Count of zeros and ones at this bit position
        int zc = 0, oc = 0;

        // Individual sum at each bit position
        long long int idsum = 0;
        for (int j = 0; j < n; j++)
        {
            // Count zero or one at current bit position
            if (arr[j] % 2 == 0)
                zc++;
            else
                oc++;
            arr[j] /= 2; // Shift array elements for next bit
        }

        // Calculating individual bit sum for this position
        idsum = oc * zc * (1LL << i);

        // Accumulate into final sum
        sum += idsum;
    }

    cout << sum;
    return 0;
}
