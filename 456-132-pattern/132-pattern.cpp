class Solution {
public:
    bool find132pattern(vector<int>& a) {
        stack<int>st;
        int n=a.size(),m=INT_MIN;
        for(int i=n-1;i>=0;i--){
            if(a[i]<m) return 1;
            while(!st.empty()&& st.top()<a[i] ){
                m=st.top();
                st.pop();
            }
            st.push(a[i]);
        }
        return false;
    }
};