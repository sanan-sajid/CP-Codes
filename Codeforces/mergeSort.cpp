#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
void merge(vector<int> &v, int l, int mid, int r, vector<int> &res)
{
  vector<int> temp(r - l + 1);
  int i = 0;
  int j = mid + 1;
  int cnt = 0;
  while (i <= mid && j <= r)
  {
    if (v[i] >= v[j])
    {
      res[i] += r + 1 - j;
      temp[cnt++] = v[i++];
    }
    else
    {

      // no impact on answer
      temp[cnt++] = v[j++];
    }
  }
  while (i <= mid)
  {
    temp[cnt++] = v[i++];
  }
  while (j <= r)
  {
    temp[cnt++] = v[j++];
  }
  for (int k = l; k <= r; k++)
  {
    v[k] = temp[k - l];
  }
}
void mergeS(vector<int> &v, int l, int r, vector<int> &res)
{
  if (r - l <= 1)
    return;
  int mid = l + (r - l) / 2;
  mergeS(v, l, mid, res);
  mergeS(v, mid + 1, r, res);
  merge(v, l, mid, r, res);
}
vector<int> countSmaller(vector<int> &nums)
{
  vector<int> res;
  mergeS(nums, 0, nums.size() - 1, res);

  return res;
}
// void merge(vector<int> &v, int l, int mid, int r)
// {
//   vector<int> temp(r - l + 1);
//   int i = 0;
//   int j = mid + 1;
//   int cnt = 0;
//   while (i <= mid && j <= r)
//   {
//     if (v[i] <= v[j])
//     {
//       temp[cnt++] = v[i++];
//     }
//     else
//     {
//       temp[cnt++] = v[j++];
//     }
//   }
//   while (i <= mid)
//   {
//     temp[cnt++] = v[i++];
//   }
//   while (j <= r)
//   {
//     temp[cnt++] = v[j++];
//   }
//   for (int k = l; k <= r; k++)
//   {
//     v[k] = temp[k - l];
//   }
// }

// void mergeSort(vector<int> &v, int l, int r)
// {
//   if (r - l <= 1)
//     return;
//   int mid = l + (r - l) / 2;
//   mergeSort(v, l, mid);
//   mergeSort(v, mid + 1, r);
//   merge(v, l, mid, r);
// }

void merge(vector<int> &v, int l, int mid, int r, int &res)
{
  vector<int> temp(r - l + 1);
  int cnt = 0;
  int i = l;
  int j = mid + 1;
  while (i <= mid && j <= r)
  {
    if (v[i] > v[j])
    {
      res++;
      temp[cnt++] = v[i++];
    }
    else
    {
      temp[cnt++] = v[j++];
    }
  }
  while (i <= mid)
  {
    temp[cnt++] = v[i++];
  }
  while (j <= r)
  {
    temp[cnt++] = v[j++];
  }
  for (int k = l; k <= r; k++)
  {
    v[k] = temp[k - l];
  }
}
int f(vector<int> &v, int l, int r, int &res)
{
  if (r <= l)
    return;
  int mid = l + (l - r) / 2;
  f(v, 0, mid, res);
  f(v, mid + 1, r, res);
  merge(v, l, mid, r, res);
}

long long inversionCount(long long arr[], long long N)
{
  vector<int> v(N);
  for (int i = 0; i < N; i++)
    v[i] = arr[i];
  int res = 0;
  f(v, 0, N - 1, res);
  return res;
}

int32_t main()
{

  vector<int> v = {3, 4, 1, 6, 2, 5, 7};
  mergeSort(v, 0, 2);
  for (auto it : v)
    cout << it << " ";
  cout << endl;

  return 0;
}
