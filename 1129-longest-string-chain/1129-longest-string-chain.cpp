class Solution {
public:
   bool ispre(string&s1,string &s2){
      if(s1.size()!=s2.size()+1) return false;
      int i=0;
      int j=0;
      int c=0;
      while(i<s2.size() && j<s1.size()){
        if(s2[i]==s1[j]){
            i++;j++;
        }else{
            j++;
            c++;
            if(c>1) return false;
        }
      }
      return true;

   }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string &s1, const string &s2) {
        return s1.size() < s2.size();
    });
    int n=words.size();
        vector<int> dp(n,1);
      for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(ispre(words[i],words[j])){
                    if(dp[i]<dp[j]+1){
                      dp[i]=dp[j]+1;
                     // h[i]=j;
                    }
                }
            }
        }
         int maxi=1;
        for(int i=0;i<n;i++){
          maxi=max(maxi,dp[i]);
        }
        return maxi;
    }
};