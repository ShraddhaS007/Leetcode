class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long int maxi=0;
        long long int mini=0;
        long long int x=0;
        int n=differences.size();
        for(int i=0;i<n;i++){
           x+=differences[i];
           maxi=max(maxi,x);
           mini=min(mini,x);
        }
        if((upper-lower)-(maxi-mini)+1>0)
        return (upper-lower)-(maxi-mini)+1;
        else return 0;
    }
};