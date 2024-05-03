class Solution {
    void solve( vector<int>& nums, int n, vector<vector<int>>& ans){
        if( n==0){
            ans.push_back( nums);
            return ;
        }
        for( int i=0;i<n;i++){
            swap( nums[i] ,nums[n-1]);
            solve( nums, n-1, ans);
            swap( nums[i],nums[n-1]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        solve( nums, nums.size(), ans);
        return ans;
    }
};