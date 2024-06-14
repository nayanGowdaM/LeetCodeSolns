class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n=nums.size(), mx=*max_element( nums.begin(), nums.end()) , ans=0;
        vector<int> freq( mx+n+1,0);
        for( auto x: nums) freq[x]++;
        for( int i=0;i<freq.size();i++){
            if(freq[i]>1){
                int dup = freq[i]-1;
                ans+=dup;
                freq[i]=1;
                freq[i+1]+=dup;
            } 
        }
        return ans;
    }
};