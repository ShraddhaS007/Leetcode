class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
    if (n == 0) return "";

    vector<vector<bool>> dp(n, vector<bool>(n, false));
     for (int i = 0; i < n; i++) dp[i][i] = true;
     int x=0;
     int ml=1;
      for(int l=2;l<=n;l++){
        for(int i=0;i<=n-l;i++){
            int j=i+l-1;
            if(s[i]==s[j]){
                if(l==2 || dp[i+1][j-1]==true){
                    dp[i][j]=true;
                    x=i;
                    ml=l;
                }
            }
        }
      }
      return s.substr(x, ml);
    }
};