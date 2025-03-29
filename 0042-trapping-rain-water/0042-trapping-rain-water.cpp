class Solution {
public:
    int trap(vector<int>& height) {
        // vector<int> ng;
        // vector<int> pg;
        // stack<int>s, st;
         int n=height.size();
         int ng[n],pg[n];
        // for(int i=n-1;i>=0;i--){
        // while(!s.empty() && s.top()<=height[i]){
        //     s.pop();
        // }
        // if(s.empty()) ng.push_back(-1);
        // else ng.push_back(s.top());
        // s.push(height[i]);
        // }
        // reverse(ng.begin(),ng.end());
        // for(int i=0;i<n;i++){
        // while(!st.empty() && st.top()<=height[i]){
        //     st.pop();
        // }
        // if(st.empty()) pg.push_back(-1);
        // else pg.push_back(st.top());
        // st.push(height[i]);
        
        // }
        int ans=0;
        // for(int i=0;i<n;i++){
        //     cout<<ng[i]<<" ";   
        // }
        // cout<<endl;
        
        // for(int i=0;i<n;i++){
          
        //     ans+=max(min(ng[i],pg[i])-height[i],0);
        // }
        pg[0]=0;
        for(int i=1;i<n;i++){
            if(max(pg[i-1],height[i-1])>height[i])
            pg[i]=max(pg[i-1],height[i-1]);
            else pg[i]=0;
        }
        ng[n-1]=0;
        for(int i=n-2;i>=0;i--){
            if(max(ng[i+1],height[i+1])>height[i])
            ng[i]=max(ng[i+1],height[i+1]);
            else ng[i]=0;
        }
         for(int i=0;i<n;i++){
            cout<<pg[i]<<" ";
        }
        cout<<endl;
        for(int i=0;i<n;i++){
            cout<<ng[i]<<" ";
        }
          for(int i=0;i<n;i++){
            ans+=max((min(ng[i],pg[i])-height[i]),0);
        }
       return ans;
    
    }
};