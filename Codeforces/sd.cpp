#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
typedef long long ll;
#define pb push_back
#define ff first
#define ss second
const int N = 3e5 + 7;
const int mod = 1e9 + 7;
const double eps = 1e-6;
const double pi = 3.14159265358979323846;
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    op_set;

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--)
  {
    ll a, b;
    cin >> a >> b;

    ll high = abs(b - a);
    ll low = 1;
    ll ans = high;
    while (low <= high)
    {
      ll mid = (low + high) / 2;

      bool flag = false;
      for (int i = 0; i <= mid; i++)
      {
        ll k = a + i;
        ll z = b | k;
        ll total = i + 1 + std::max(0ll, z - b);

        ll k2 = b + i;
        ll x = a | k2;
        ll total2 = i + 1 + std::max(0ll, x - k2);
        if (total <= mid || total2 <= mid)
        {
          flag = true;
          cout << mid << " " << i << endl;
        }
      }

      if (flag)
      {
        ans = std::min(ans, mid);
        high = mid - 1;
      }
      else
        low = mid + 1;
    }
    cout << ans << "\n";
  }
}