class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int>st;
        int ans = -1;
        for( auto x: nums){
            if(st.find( -x)!=st.end()){
                ans = max( ans, abs(x));
            }
            else st.insert(x);
        }
        return ans;
    }
};