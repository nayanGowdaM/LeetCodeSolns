class Solution {
    vector<vector<int>> ans;

    void solve( int n , vector<int>& nums, vector<int>& res){
        if( n==0) {
            ans.push_back( res);
            return ;

        }
        if( n<0) return;
        res.push_back( nums[n-1]);
        solve( n-1, nums, res);
        res.pop_back();

        while( n>1 && nums[n-1]==nums[n-2]) n--;
        solve( n-1, nums, res);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort( nums.begin(), nums.end());
        vector<int> res;
        solve( nums.size(), nums, res);
        return ans;
    }
};