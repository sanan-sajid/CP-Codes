#include <bits/stdc++.h>
using namespace std;
int makeTheIntegerZero(int num1, int num2)
{
    int x = 1;
    for (; x < 100; x++)
    {
        long long y = num1 - num2 * x;
        int setBits = __builtin_popcountll(y);
        if (x >= setBits && x <= y)
            return x;
    }
    return -1;
}

int main()
{
    cout << makeTheIntegerZero(3, -2);
    cout << makeTheIntegerZero(5, 7);
    return 0;
}
