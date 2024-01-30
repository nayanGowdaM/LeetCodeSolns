class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> ans;
        for( auto& x: nums){
            auto it= lower_bound(ans.begin(),ans.end(),x) - ans.begin();
            if(it==ans.size()) ans.push_back(x);
            else
            ans[it]=x;
        }
        return ans.size();
    }
};