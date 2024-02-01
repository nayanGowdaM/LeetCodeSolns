class Solution {
    bool is_valid( vector<int>& nums, int i, int k){
        return abs(nums[i]-nums[i+1]) <=k  && abs(nums[i+1]-nums[i+2]) <=k  && abs(nums[i]-nums[i+2])<=k ;
    }
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n=nums.size();
        sort( nums.begin(), nums.end());
        vector<vector<int>>ans;
        for( int i=0;i<n;i+=3){
            if( !is_valid(nums,i,k)) return {};
            vector<int> temp;
            for( int j=i;j<=i+2;j++) temp.push_back(nums[j]);
            ans.push_back(temp);
        }
        return ans;
    }
};