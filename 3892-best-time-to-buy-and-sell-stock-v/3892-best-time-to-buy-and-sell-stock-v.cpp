class Solution {
public:
    long long  fun(vector<int>& a, int n, int i, int b,int x, int k, vector<vector<vector<vector<long long >>>>& dp){
        if(i==n-1 && x==0) return 0; 
        if (i == n || k == 0) return 0;

    if (dp[i][b][x][k] != -1)
        return dp[i][b][x][k];

    long long p;
        if(x==0){
            p=max(fun(a,n,i+1,b,x,k,dp),max(-a[i]+fun(a,n,i+1,1,1,k,dp),+a[i]+fun(a,n,i+1,0,1,k,dp)));
        }
        else{
            if(i==n-1){
                if(b==0) p=-a[i]+fun(a,n,i+1,b,0,k-1,dp);
                else p=+a[i]+fun(a,n,i+1,b,0,k-1,dp);
            }else{
            if(b==0){
               p=max(fun(a,n,i+1,b,x,k,dp),-a[i]+fun(a,n,i+1,b,0,k-1,dp));
            }
            else{
                p=max(fun(a,n,i+1,b,x,k,dp),+a[i]+fun(a,n,i+1,b,0,k-1,dp));
            }
            }     
        }
        return dp[i][b][x][k]=p;

    }
   
    long long maximumProfit(vector<int>& prices, int k) {
        int n=prices.size();
        vector<vector<vector<vector<long long>>>> dp(
    n, vector<vector<vector<long long>>>(
        2, vector<vector<long long>>(
            2, vector<long long>(k + 1, -1)
        )
    )
); 
     long long ans=fun(prices, n, 0, 0,0, k, dp);
          cout<<fun(prices,n,2,0,1,1,dp);cout<<endl;
    //    cout<<dp[1][1][1][1]-1;cout<<endl;
    //    cout<<dp[1][0][1][1]+1;
        return ans;
        
    }
};