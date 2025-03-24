class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0;
        int j=0;
        int n=s.size();
        map<char,int> m;
        int x=0;
        while(j<n){
             while(m[s[j]]>0){
                    m[s[i]]--;
                    i++;
            }
            x=max(x,j-i+1);
            m[s[j]]++;
            j++;
        }
        return x;
    }
};