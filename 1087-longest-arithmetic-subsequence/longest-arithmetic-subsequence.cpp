class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        unordered_set<int> st;
        int n=nums.size();
        for( int i=0;i<n-1;i++){
            for( int j=i+1;j<n;j++) st.insert( nums[j]-nums[i]);
        }

        int ct=INT_MIN;
        for( auto it: st){
            unordered_map<int ,int> mp;
            mp[nums[0]]=1;
            for( int i=1;i<n;i++){
                if( mp.find( nums[i]-it)==mp.end()) mp[nums[i]]=1;
                else mp[nums[i]]=mp[nums[i]-it]+1;
            }
            for( auto itr=mp.begin();itr!=mp.end();itr++) ct=max(ct, itr->second);
        }
        return ct; 
    }
};