class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long firstMiss=1, idx=0, miss=0;
        while( firstMiss<=n){
            if(idx<nums.size() && firstMiss >= nums[idx]){
                firstMiss+=nums[idx++];
            }
            else{
                miss++;
                firstMiss+= firstMiss;
            }
        }
        return miss;
    }
};