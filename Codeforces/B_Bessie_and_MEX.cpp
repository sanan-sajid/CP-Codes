#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };


bool func(int i,int n,vector<int>&dp,vector<int>&v,int tar){
    cout<<i<<" ";
    if(i>n){
        return dp[i]=0;
    }
    if(v[i]+i==tar){
        return dp[i]=1;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    return dp[i]=func(i+v[i],n,dp,v,tar);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--){
        ll m,n;
        cin>>n>>m;
        vector<int>v(n+1);
        for(int i=0;i<n;i++){
            cin>>v[i+1];
        }
        vector<int>dp(2*n+1,-1);
        for(int i=1;i<=n;i++){
            func(i,n,dp,v,m);
            cout<<dp[i]<<" ";
        }
        ll ans=0;
        for(int i=1;i<=n;i++){
            ans+=dp[i];
        }
        cout<<ans<<endl;
    }
    
}