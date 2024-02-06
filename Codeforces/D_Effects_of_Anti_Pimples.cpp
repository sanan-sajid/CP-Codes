#include <iostream>
using namespace std;

int main()
{
    int n = 6;
    int matrix[n][n];
    int num = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = num++;
        }
    }

    int top = 0, bottom = n - 1, left = 0, right = n - 1;

    while (top <= bottom && left <= right)
    {
        for (int i = top; i <= bottom; i++)
        {
            cout << matrix[i][left] << " ";
        }
        left++;

        for (int i = left; i <= right; i++)
        {
            cout << matrix[bottom][i] << " ";
        }
        bottom--;

        if (top <= bottom)
        {
            for (int i = bottom; i >= top; i--)
            {
                cout << matrix[i][right] << " ";
            }
            right--;
        }

        if (left <= right)
        {
            for (int i = right; i >= left; i--)
            {
                cout << matrix[top][i] << " ";
            }
            top++;
        }
    }

    return 0;
}
