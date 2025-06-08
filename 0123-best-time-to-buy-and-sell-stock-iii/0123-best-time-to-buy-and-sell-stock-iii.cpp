class Solution {
public:
      int fun(vector<int>&a,int n,int i,int x,int k, vector<vector<vector<int>>>&dp){
      if(i==n || k<0) return 0;
      if (dp[i][x][k]!=-1) return dp[i][x][k];
      int profit;
      if(x==0){
         profit=max(0+fun(a,n,i+1,0,k,dp),
             -a[i]+fun(a,n,i+1,1,k,dp));
      }
      if(x==1){
          profit=max(0+fun(a,n,i+1,1,k,dp),
             a[i]+fun(a,n,i+1,0,k-1,dp));
      }
      return dp[i][x][k]=profit;
   }
    int maxProfit(vector<int>& prices) {
             int n=prices.size();
         vector<vector<vector<int>>>dp (n,vector<vector<int>>(2,vector<int>(2,-1)));
         return fun(prices,n,0,0,1,dp);
    }
};