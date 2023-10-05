class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int ,int> mp;
        int n=floor(nums.size()/3);
        vector<int> ans;
        for(auto x: nums) mp[x]++;
        for(auto it: mp) if(it.second>n) ans.push_back(it.first);
        return ans;
    }
};