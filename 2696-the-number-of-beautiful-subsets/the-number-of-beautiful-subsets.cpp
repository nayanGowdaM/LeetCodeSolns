class Solution {
    int ans = 0;
    void solve(vector<int>& nums, int idx, vector<int>& subset, int k){
        if( idx== nums.size()){
             ans++;
             return ;
             }
        solve(nums, idx+1, subset, k);
        auto  x = lower_bound( subset.begin(), subset.end(),nums[idx] - k);
        if(x==subset.end() || *x !=nums[idx]-k ){
            subset.push_back( nums[idx]);
            solve( nums, idx+1, subset, k);
            subset.pop_back();
        }
    }
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        sort( nums.begin(), nums.end());
        vector<int> res;
        solve( nums, 0,res,k );
        return ans-1;
    }
};