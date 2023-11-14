class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        int n=a.size();
        stack<int> st;
        for(int i=0;i<n;i++){
            if(a[i]>0 || st.empty()) st.push(a[i]);
            else{
                while(!st.empty() && st.top()>0 && abs(a[i])>abs(st.top())) st.pop();
                if(st.empty() || st.top()<0) st.push(a[i]);
                else{
                    if(abs(st.top())==abs(a[i])) st.pop();
                }
            }
        }
        vector<int> v;
        while(!st.empty()) {
            v.push_back(st.top());
            st.pop();
        }
        reverse(v.begin(),v.end());
        return v;
    }
};