class Solution {
public:

    int fun(vector<int>&a,int n,int i,int x,int f, vector<vector<int>>&dp){
      if(i==n ) return 0;
      if (dp[i][x]!=-1) return dp[i][x];
      int profit;
      if(x==0){
         profit=max(0+fun(a,n,i+1,0,f,dp),
             -a[i]+fun(a,n,i+1,1,f,dp));
      }
      if(x==1){
          profit=max(0+fun(a,n,i+1,1,f,dp),
            -f+a[i]+fun(a,n,i+1,0,f,dp));
      }
      return dp[i][x]=profit;
   }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
         vector<vector<int>>dp (n,vector<int>(2,-1));
         return fun(prices,n,0,0,fee,dp);
    }
};