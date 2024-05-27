class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort( nums.begin(), nums.end());
        int n=nums.size();
        for( int i=0;i<n-3;i++){
            if( i==0 || nums[i-1]!=nums[i]){
                for( int j=i+1;j<n-2;j++){
                    if(j==i+1 ||  nums[j-1]!=nums[j]){
                        int s=j+1, e=n-1;
                        while( s<e){
                            long long  sum = 0ll + nums[i] + nums[j] + nums[s] + nums[e];
                            if( sum > target)e--;
                            else if( sum < target) s++;
                            else{
                                ans.push_back({nums[i],nums[j], nums[s],nums[e]});
                                s++;
                                e--;
                                while (s < e && nums[s] == nums[s - 1]) s++;
                                while (s < e && nums[e] == nums[e + 1]) e--;
                            }

                        }
                    }
                }

            }
        }
        return ans;
    }
};