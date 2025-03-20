class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> v;
        int a,b,c,d;
        a=c=0;
        b=n-1;
        d=m-1;
        int i=0;
        int j=0;
        while(a<=b && c<=d){
            for(int i=c;i<=d;i++){
                v.push_back(matrix[a][i]);
            }
            a++;
            for(int i=a;i<=b;i++){
                v.push_back(matrix[i][d]);
            }
            d--;
            if(a<=b){
            for(int i=d;i>=c;i--){
                v.push_back(matrix[b][i]);
            }
            b--;
            }
            if(c<=d){
             for(int i=b;i>=a;i--){
                v.push_back(matrix[i][c]);
            }
            c++;
            }
            
        }
        return v;
        
    }
};