class Solution {
public:
  int fun(string &a,string &b,vector<vector<int>>&dp,int i,int j){
     if(i<0 || j<0) return 0;
     if(dp[i][j]!=-1) return dp[i][j];
     if(a[i]==b[j]) return dp[i][j]=fun(a,b,dp,i-1,j-1)+1;
     else return dp[i][j]=max(fun(a,b,dp,i-1,j),fun(a,b,dp,i,j-1));
  }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return (n+m)-2*fun(word1,word2,dp,n-1,m-1);
    }
};