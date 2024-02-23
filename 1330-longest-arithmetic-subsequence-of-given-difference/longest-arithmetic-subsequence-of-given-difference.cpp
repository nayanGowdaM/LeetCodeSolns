class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
        unordered_map<int,int> mp;
        mp[arr[0]]=1;
        int n=arr.size();
        for( int i=1;i<n;i++){
            if( mp.find( arr[i]-diff)==mp.end()){
                mp[arr[i]]=1;
            }
            else {
                mp[arr[i]]=mp[arr[i]-diff] + 1;
            }
        }
        int ans=INT_MIN;
        for( auto it=mp.begin();it!=mp.end();it++){
            ans=max(ans, it->second);
        }
        return ans;
    }
};