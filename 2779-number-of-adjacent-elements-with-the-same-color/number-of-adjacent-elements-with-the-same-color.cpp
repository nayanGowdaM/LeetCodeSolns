class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& q) {
        vector<int> res, nums(n,0);
        int c=0;
        for( auto x: q){
            int idx = x[0] , color = x[1];
            int prev = idx>0 ? nums[idx-1] : 0;
            int next = idx<n-1?nums[idx+1] : 0;
            if(nums[idx] && nums[idx]==prev ) c--;
            if(nums[idx] && nums[idx]==next ) c--;
            nums[idx] = color;
            if(prev == nums[idx]) c++;
            if(next == nums[idx]) c++;

            res.push_back( c);
        }
        return res;
    }
};