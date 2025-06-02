class Solution {
public:
    int allstar(string &S1, int i) {
    for (int j = 0; j <= i; j++) {
        if (S1[j] != '*')
            return 0;
    }
    return 1;
}
    int fun(string&s, string &p, vector<vector<int>> &dp,int i,int j,int n,int m){
        
        if(i<0 && j<0) return 1;
        if(j<0 && i>=0) return 0;
        if(i<0 && j>=0) return allstar(p,j);
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==p[j]) {
            return dp[i][j]=fun(s,p,dp,i-1,j-1,n,m);
        }else {
            if(p[j]=='?') return dp[i][j]=fun(s,p,dp,i-1,j-1,n,m);
            else if(p[j]=='*') return dp[i][j]=fun(s,p,dp,i-1,j,n,m)|| fun(s,p,dp,i,j-1,n,m);
            else return 0;
        }
        return dp[n-1][m-1];

    }
    bool isMatch(string s, string p) {
            int n = s.size();
    int m = p.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return fun(s, p,dp, n - 1, m - 1,n,m);
    }
    
};