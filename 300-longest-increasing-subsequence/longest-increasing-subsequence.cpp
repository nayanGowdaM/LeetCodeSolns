class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        set<pair<int,int>> st;
        st.insert( {-1,nums[0]});
        for( int i=1;i<nums.size(); i++){
            auto it=st.begin();
            while( it!= st.end() && it->second>=nums[i]) it++;
            if( it==st.end()) st.insert({-1,nums[i]});
            else st.insert({it->first-1, nums[i]}); 
        }
        return -st.begin()->first ;
    }
};