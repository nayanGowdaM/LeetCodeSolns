class Solution {
    vector<vector<int>> ans;
    void solve( int n,vector<int>& nums, vector<int>& res){
        if( n==0){
            ans.push_back(res);
            return;
        }
        solve( n-1,nums, res);
        res.push_back( nums[n-1]);
        solve( n-1 , nums, res);
        res.pop_back( );
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> res;
        solve( nums.size(), nums, res);
        return ans;
    }
};