int n;
int dp[1000];
int f(vector<int> &arr, int k, int i)
{
  if (i >= arr.size())
    return 0;
  if (dp[i] != -1)
    return dp[i];
  int notTaken = f(arr, k, i + 1);
  int taken = 0;

  int maxi = -1;
  for (int j = i; j < min(n, i + k); j++)
  {
    maxi = max(arr[j], maxi);
    taken = max(taken, f(arr, k, j + 1) + (j - i + 1) * maxi);
  }

  return dp[i] = max(taken, notTaken);
}

int maxSumAfterPartitioning(vector<int> &arr, int k)
{
  memset(dp, -1, sizeof(dp));
  n = arr.size();
  return f(arr, k, 0);
}