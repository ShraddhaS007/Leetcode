class Solution {
public:
    string fun(string s,int n,int x,string k){
         
   // int n=s.size();
    vector<int> z(n,0);
    int L = 0, R = 0;
    for (int i = 1; i < n; i++) {
        if (i > R) {
         L = R = i;
        while (R < n && s[R-L] == s[R]) R++;
         z[i] = R-L; R--;
        } else {
           int k = i-L;
           if (z[k] < R-i+1) z[i] = z[k];
          else {
             L = i;
             while (R < n && s[R-L] == s[R]) R++;
               z[i] = R-L; R--;
         }
       }     
    }
    int ans=0;
 
    for(int i=x+1;i<n;i++){
       // cout<<z[i]<<" ";
        if(z[i]==n-i)
        ans=max(ans,z[i]);
    }
    // cout<<endl;
     cout<<ans<<endl;
    string aa="";
    for(int i=x-1;i>=ans;i--){
        aa+=k[i];
    }
    aa+=k;
   // cout<<endl;
    return aa;
 }
    string shortestPalindrome(string s) {
        int n=s.size();
        string st="";
        st+=s;
        st+="$";
        reverse(s.begin(),s.end());
        st+=s;
         reverse(s.begin(),s.end());
        return fun(st,st.size(),n,s);
     
    }
};