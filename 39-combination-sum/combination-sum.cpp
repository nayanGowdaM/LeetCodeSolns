class Solution {
public:
    vector<vector<int >> v;
    void solve(vector<int >& a,vector<int>& ans , int i,int t ){
        if(i==a.size()){
            if(!t ) v.push_back(ans);
            return ;
        }
        if(a[i]<=t) {
            ans.push_back(a[i]);
            solve(a,ans,i,t-a[i]);
            ans.pop_back();
        }
        solve(a,ans,i+1,t);
    }
    vector<vector<int>> combinationSum(vector<int>& a, int t) {
        vector<int> ans;
        solve(a,ans,0,t);
        return v;
    }
};