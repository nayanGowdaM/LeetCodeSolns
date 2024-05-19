class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int cur=0, prev =0 , n=nums.size();
        // unordered_map<int, pair<int,int>>mp;
        // map<int,int>mp;
        int m = queries.size();
        vector<bool> ans;
        vector<int> dp(n,-1);
        while( cur<n){
            if( cur==prev){
                dp[cur]=prev;
                cur++;
                
            }
            else{
                if( nums[cur]%2  != nums[cur-1]%2){
                    // s.insert( {prev, cur});
                    dp[cur]=prev;
                    cur++;
                    
                    
                } 
                else{
                    // mp[cur-prev] = {prev, cur-1};=
                    // mp[cur-1]=prev;
                    prev = cur;
                }
            }
        }
        for(auto x: queries){
            if(dp[x[1]] <= x[0]) ans.push_back( true);
            else ans.push_back( false);
        }
        return ans;

    }
};