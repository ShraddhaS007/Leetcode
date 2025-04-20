class Solution {
public:
    int numRabbits(vector<int>& answers) {
        vector<int> v(1001,0);
        int n=answers.size();
        int ans=0;
        for(int i=0;i<n;i++){
            v[answers[i]]++;
        }
        for(int i=0;i<=1000;i++){
            if(v[i]==0) continue;
            if(v[i]%(i+1)==0) ans+=v[i];
            else ans+=(v[i]/(i+1))*(i+1)+i+1;       
        }
        return ans;

    }
};