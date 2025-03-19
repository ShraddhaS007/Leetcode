class Solution {
public:
    void fun(string &s,int l,int r){
        string a="";
        for(int i=l+1;i<=r-1;i++){
            a+=s[i];
        }
        int j=l+1;
        for(int i=a.size()-1;i>=0;i--){
            s[j]=a[i];
            j++;
        }
       
    }
    string reverseParentheses(string s) {
        stack<int> st;
       
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') st.push(i);
            if(s[i]==')') {
                fun(s,st.top(),i);
                st.pop();
            }
        }
        string b="";
        for(int i=0;i<s.size();i++){
            if(s[i]!=')' && s[i]!='('){
                b+=s[i];
            }
        }
        return b;
    }
};