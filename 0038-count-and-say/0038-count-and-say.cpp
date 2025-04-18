class Solution {
public:
     string anss(string s){
        string ans;
        int i=0;
        while(i<s.size()){
            int c=1;
            while(i<s.size()-1 && s[i]==s[i+1]){
                c++;
                i++;
            }
            ans+=to_string(c);
            ans+=s[i];
            i++;
        }
        return ans;
    }
    string countAndSay(int n) {
        string an="1";
        if(n==1) {
            return an;
        }
        for(int i=1;i<n;i++){
           an=anss(an);
        }
        return an;
    }
};