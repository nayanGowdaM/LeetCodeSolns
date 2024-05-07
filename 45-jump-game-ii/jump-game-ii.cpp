class Solution {
    int min_ele( vector<int>& ans, int n, int l){
        int mn=ans[n];
        for( int i=n+1;i<ans.size() && i<= n+l;i++) mn = min( mn, ans[i]);
        return mn;
    }
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans( n, INT_MAX);
        ans[n-1] = 0;
        for( int i=n-2;i>=0 ;i--){
            int val = min_ele( ans, i, nums[i]);
            if(val == INT_MAX) val--;
            ans[i] = 1 + val;
            cout<<ans[i]<<endl;
        }
        return ans[0];
    }
};