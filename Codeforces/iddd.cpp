#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define ld long double

//---------------------CONSTANTS---------------------/
#define M 1000000007
#define N 100005

//---------------------PB_DS---------------------/
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

// int : is type of data to insert into tree
// null_type : part of maping
// less : ascending // greater // less_equal
// pbds A for itialization
// kth element : .find_by_order
// no of small ele : .order_of_key

//---------------------Segment Tree---------------------/

vector<ll> seg(N);

void Segment_Tree_Build(ll ind, ll low, ll high, vector<ll> &a)
{
  if (low == high)
  {
    seg[ind] = a[low];
    return;
  }
  ll mid = (low + high) / 2;
  Segment_Tree_Build(2 * ind + 1, low, mid, a);
  Segment_Tree_Build(2 * ind + 2, mid + 1, high, a);
  seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);
}

ll Segment_Tree_Query(ll ind, ll low, ll high, ll l, ll r)
{
  if (low >= l && high <= r)
  {
    return seg[ind];
  }
  if (high < l || low > r)
  {
    return INT_MIN;
  }
  ll mid = (low + high) / 2;
  ll left = Segment_Tree_Query(2 * ind + 1, low, mid, l, r);
  ll right = Segment_Tree_Query(2 * ind + 2, mid + 1, high, l, r);
  return max(left, right);
}
void Segment(vector<ll> &a, ll q)
{
  Segment_Tree_Build(0, 0, (a.size() - 1) * 1ll, a);
  while (q--)
  {
    ll l, r;
    cin >> l >> r;
    cout << Segment_Tree_Query(0, 0, (a.size() - 1) * 1ll, l, r) << endl;
  }
  // cout<<endl;
}

//---------------------INPUT/OUTPUT---------------------/

template <typename typA>
istream &operator>>(istream &cin, vector<typA> &v)
{
  for (auto &x : v)
  {
    cin >> x;
  }
  return cin;
}
template <typename typA>
ostream &operator<<(ostream &cin, vector<typA> &v)
{
  for (auto &x : v)
  {
    cout << x << " ";
  }
  cout << "\n";
  return cout;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t = 1;
  // cin>>t;
  while (t--)
  {
    ll n, m;
    cin >> n >> m;
    vector<ll> v(n);
    cin >> v;
    pbds A;
    for (int i = 0; i < m; i++)
    {
      A.insert(v[i]);
    }
    auto it = A.begin();
    cout << *A.find_by_order((m / 2)) << " ";
    for (int i = m; i < n; i++)
    {
      A.insert(v[i]);
      A.erase(it);
      cout << *A.find_by_order((m / 2)) << " ";
      it++;
    }
    cout << endl;
  }
  return 0;
}