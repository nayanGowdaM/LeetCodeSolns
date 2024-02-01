class Solution {
    bool is_valid( vector<int>& nums, int i, int k){
        return abs(nums[i]-nums[i+1]) <=k  && abs(nums[i+1]-nums[i+2]) <=k  && abs(nums[i]-nums[i+2])<=k ;
    }
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n=nums.size();
        sort( nums.begin(), nums.end());
        vector<vector<int>>ans;
        for( int i=0;i<= n-3;i++){
            if(  is_valid(nums,i,k)) {
                vector<int> temp;
                temp.push_back(nums[i]);
                temp.push_back(nums[i+1]);
                temp.push_back(nums[i+2]);
                ans.push_back(temp);
                i=i+2;
            }
            else return {};
        }
        return ans;
    }
};