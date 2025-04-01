class Solution {
public:
string removeLeadingZeros(string s) {
    int i = 0;
    while (i < s.size() && s[i] == '0') i++; 
    return (i == s.size()) ? "0" : s.substr(i);
}
    string removeKdigits(string num, int k) {
        int n=num.size();
        stack<int> s;
        int c=0;
        for(int i=0;i<n;i++){   
            while(!s.empty() && c!=k && s.top()>num[i]){
              s.pop();
              c++;
              if(c==k) break;
            }
            s.push(num[i]);
        }
        while(s.size()>n-k){
           // num[s.top().second]='a';
            s.pop();
        }
        // for(auto it : s){
        //     num[it.second]='a';
        // }
        string ans="";
        while(!s.empty()){
            ans+=(char)(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        // for(int i=0;i<n;i++){
        //     if(num[i]!='a') ans+=num[i];
        // }

        if(ans=="") return "0";
        return removeLeadingZeros(ans);
    }
};