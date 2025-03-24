class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        map<char,int>m;
        for(int i=0;i<t.size();i++){
            m[t[i]]++;
        }
        int nn=m.size();

        int i=0;
        int j=0;
        int x=-1;
        int c=0;
        int ml=INT_MAX;
        while(j<n){
            m[s[j]]--;
            if(m[s[j]]==0) c++;
            if(c==nn){
                while(i<n && m[s[i]]<0){
                    m[s[i]]++;
                    i++;
                } 
                //cout<<i<<" "<<j<<endl;
                if(j-i+1<ml){
                      x=i;
                      ml=j-i+1;
                }
                if(m[s[i]]==0)  c--;
                m[s[i]]++;
                i++;    
            }
            j++;
        }
        if(x==-1) return "";
        return s.substr(x,ml);
    }
};