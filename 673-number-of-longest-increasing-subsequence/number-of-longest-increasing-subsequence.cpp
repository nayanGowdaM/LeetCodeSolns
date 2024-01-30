class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size()  ,  ans=0,  ct=0;
        vector<int> length(n,1),count(n,1);
        for( int i=0;i<n;i++){
            for( int j=0;j<i ;j++){
                if(nums[i] > nums[j]){
                    if( length[j] + 1 > length[i]){
                        length[i] = length[j] + 1;
                        count[i]=0;
                    }
                    if( length[j] + 1 ==length[i]) count[i]+=count[j];
                }
            }
        }
        ans=*max_element(length.begin(), length.end());
        for( int i=0;i<n;i++){
            if(length[i]==ans) ct+=count[i];
        }
        return ct;
    }
};