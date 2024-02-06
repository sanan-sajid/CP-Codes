#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool customComparator(const pair<pair<int, int>, int> &a, const pair<pair<int, int>, int> &b)
{
    return a.first < b.first; // Compare only based on the first pair
}

int main()
{
    vector<pair<pair<int, int>, int>> vec = {{{3, 2}, 5}, {{1, 4}, 2}, {{1, 3}, 1}};

    sort(vec.begin(), vec.end(), customComparator);

    // Output the sorted vector
    for (const auto &elem : vec)
    {
        cout << "(" << elem.first.first << ", " << elem.first.second << "), " << elem.second << "\n";
    }

    return 0;
}
