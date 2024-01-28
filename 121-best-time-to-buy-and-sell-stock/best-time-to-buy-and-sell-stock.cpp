class Solution {
public:
    int maxProfit(vector<int>& st) {
        int m=st[0], n=st.size(),ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans, st[i]-m);
            m=min(m, st[i]);
        }
        return ans;
    }
};