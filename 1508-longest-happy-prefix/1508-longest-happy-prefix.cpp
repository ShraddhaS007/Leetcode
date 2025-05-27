class Solution {
public:
    string longestPrefix(string s) {
        vector<int> lps;
        lps.push_back(0);
        int l=0;
        int i=1;
        while(i<s.size()){
            if(s[i]==s[l]){  
                l++;
                lps.push_back(l);
                i++;
            }else{
                if(l==0){
                    lps.push_back(0);
                    i++;
                }else{
                    l=lps[l-1];
                }
            }
        }

        // for(int i=0;i<s.size();i++){
        //     cout<<lps[i]<<" ";
        // }
        string ans="";
        for(int i=0;i<lps[s.size()-1];i++){
            ans+=s[i];
        }
        return ans;

        
    }
};