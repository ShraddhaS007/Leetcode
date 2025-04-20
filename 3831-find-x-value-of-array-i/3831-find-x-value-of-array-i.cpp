class Solution {
public:
    int fun(vector<int>& nums, int n,int k,vector<vector<int>>&dp,int x){
        if(n==0){
            if(nums[n]%x==k) return dp[n][k]=1;
            else return dp[n][k]=0;
        }
        if(k==0){
            if(x==4 && nums[n]%x==2) return dp[n][k]=dp[n-1][k]+dp[n-1][2];
            if(nums[n]%x!=0) return dp[n][k]=dp[n-1][k];
            else return dp[n][k]=n+1;
        }
        if(dp[n][k]!=-1) return dp[n][k];
        if(nums[n]%x==0) return dp[n][k]=0;
        else{
            dp[n][k]=0;
            int c=k;
            while(c/(nums[n]%x)<x){
                if(c%(nums[n]%x)==0) dp[n][k]+=fun(nums,n-1,(c/(nums[n]%x)),dp,x);
                c+=x;
            }
            if(nums[n]%x==k) dp[n][k]+=1;
            return dp[n][k];
        }
        
        
        return dp[n][k]=0;
    }
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long long> v;
       vector<vector<int>> dp(n,vector<int>(k,-1));
       for(int i=0;i<k;i++){
        v.push_back(0);
       }
       for(int i=0;i<n;i++){
          for(int j=0;j<k;j++){
            
                v[j]+=fun(nums,i,j,dp,k);
          }
         
       }
       return v;

    }
};