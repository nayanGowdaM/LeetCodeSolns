class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size(),i=0,j=0,m=0,ans=0;
        while(j<n){
            if(nums[j]==1 && m<=k) ans=max(ans,j-i+1);
            else{
                m++;
                if(m<=k){ 
                    ans=max(ans,j-i+1);}
                else{
                    while(m>k){
                        if(nums[i]==0) m--;
                        i++;
                    }
                    
                }
            }
            j++;
        }
        return ans;
    }
};