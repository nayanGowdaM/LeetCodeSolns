class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> mp;
        int n= min<int>( k+1, nums.size());
        for(int i=0;i< n ;i++){
            if(mp.find( nums[i]) == mp.end()) mp.insert(nums[i]);
            else return true;
        }

        int j=n;
        for( int i=0;j<nums.size();){
            
           mp.erase( nums[i]);
            i++;
            if( mp.find(nums[j])!=mp.end()) return true;
            else mp.insert(nums[j]);
            j++;

        }
        return false;
    }
};