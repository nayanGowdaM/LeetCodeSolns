class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        int n=a.size();
        vector<int>pos(n,-1),neg(n,-1);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            if(a[i]>0){
                if(!st.empty()){
                    while(!st.empty() && a[i]>abs(st.top())) st.pop();
                    if(!st.empty()){
                        pos[i]=1;
                        if(st.top()*-1 == a[i]) st.pop();
                    }
                }
            }
            else st.push(a[i]);
        }
        while(!st.empty()) st.pop();
        for(int i=0;i<n;i++){
            if(a[i]<0){
                if(!st.empty()){
                    while(!st.empty() && abs(a[i])>abs(st.top())) st.pop();
                    if(!st.empty()){
                        neg[i]=1;
                        if(abs(st.top()) == abs(a[i])) st.pop();
                    }
                }
            }
            else st.push(a[i]);
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(pos[i]==-1 && neg[i]==-1) ans.push_back(a[i]);
        }
        return ans;
    }
};