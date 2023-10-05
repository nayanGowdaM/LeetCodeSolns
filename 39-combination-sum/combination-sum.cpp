class Solution {
public:
    vector<vector<int >> v;
    void solve(vector<int >& a,vector<int>& ans , int i,int t ){
        if(!t ) {
            v.push_back(ans);
            return;
        }
        while(i<a.size() && t-a[i]>=0){
            ans.push_back(a[i]);
            solve(a,ans,i,t-a[i]);
            i++;
            ans.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& a, int t) {
        vector<int> ans;
        sort(a.begin(),a.end());
        a.erase(unique(a.begin(),a.end()),a.end());
        solve(a,ans,0,t);
        return v;
    }
};