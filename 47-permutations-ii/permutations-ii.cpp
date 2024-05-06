class Solution {
    vector<vector<int>> ans;
    void solve( int idx, vector<int>& res, vector<int>& nums){
        if(idx == nums.size()){
            ans.push_back(res);
            return;
        }
        unordered_set<int> st;
        for( int i=idx;i<nums.size();i++){
            if( st.find( nums[i]) == st.end()){
                st.insert( nums[i]);
                res.push_back( nums[i]);
                swap(nums[i], nums[idx]);
                solve( idx +1 , res, nums);
                swap(nums[i], nums[idx]);
                res.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> res;
        solve( 0, res, nums);
        return ans;
    }
};