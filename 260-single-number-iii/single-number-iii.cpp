class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_set<int> st;
        for( auto x: nums) {
            if( st.find( x)==st.end()) st.insert( x);
            else st.erase(x);
        }
        vector<int> ans( st.begin() , st.end());
        return ans;
    }
};