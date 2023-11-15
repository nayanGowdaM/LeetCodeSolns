class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k==0) return num;
        string res;
        int n=num.size();
        if(k>=n) return "0";
        stack<char>st;
        st.push(num[0]);
        for(int i=1;i<n;i++){
            while(k>0 && !st.empty() && st.top()>num[i]){
                k--;
                st.pop();
            }
            st.push(num[i]);
            if(st.size()==1 && st.top()=='0') st.pop();
        }
        while(k>0 && !st.empty()){
            k--;
            st.pop();
        }
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res.size()?res:"0";
    }
};