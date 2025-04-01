class Solution {
public:

    int abs(int a){
        if(a<0) return a*-1;
        return a;
    }
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n=asteroids.size();
        vector<int> v;
        stack<int> s;
        for(int i=0;i<n;i++){
            int f=0;
            while(!s.empty() && asteroids[i]<0 && s.top()>0){
              if(abs(asteroids[i])<abs(s.top())){
                f=1;
                break;
              }
              else if(abs(asteroids[i])==abs(s.top())) {
                s.pop();
                f=1;
                break;
              }
              else s.pop();
            }
           if(f==0) s.push(asteroids[i]);
        }
        while(!s.empty()){
            v.push_back(s.top());
            s.pop();
        }
        reverse(v.begin(),v.end());
        return v;

    }
};