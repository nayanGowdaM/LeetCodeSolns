class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n=temp.size();
        stack<int> st;
        st.push(n-1);
        vector<int> ans(n,0);
        for(int i=n-2;i>=0;i--){
            while(!st.empty() && temp[st.top()] <= temp[i])  st.pop();
            int idx=i;
            if(!st.empty()) idx=st.top();
            st.push(i);
            ans[i]= idx-i;

        }
        return ans;
    }
};