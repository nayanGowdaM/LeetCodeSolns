class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans=0;
        int prevMin=-1, prevMax=-1;
        bool valid=false;
        int start=0, end=0, n=nums.size();
        while(end<n){
            if( nums[end]>maxK || nums[end]<minK){
                start=end+1;
                end=end+1;
                valid=false;
                prevMin=-1;
                prevMax=-1;
            }
            else{
                if(nums[end]==minK){
                    prevMin=end;
                    if(prevMax!=-1) valid=true;
                }
                if( nums[end]==maxK){
                    prevMax=end;
                    if(prevMin!=-1) valid=true;
                }
                if( valid){
                    ans+= ( min(prevMin, prevMax) - start+1) ;
                }
                end++;
            }
            
        }
        return ans;
    }
};