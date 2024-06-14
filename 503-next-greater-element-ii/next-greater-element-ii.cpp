class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        nums.insert( nums.end(), nums.begin(), nums.end());
        for( auto x: nums) cout<<x<<" ";
        vector<int> ans(n,0);
        stack<int> st;
        for(int i=2*n-1;i>=0;i--){
            while( !st.empty() && st.top()<=nums[i]) st.pop();
            if( i<n){
                if(st.empty()) ans[i]=-1;
                else ans[i] = st.top();
            }
            st.push( nums[i]);
        }
        return ans;

    }
};