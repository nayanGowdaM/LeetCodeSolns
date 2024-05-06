class Solution {
    vector<vector<int>> ans;
    void solve(int tar, int n , vector<int>& cand, vector<int>& res ){
        if( tar == 0){
            ans.push_back( res);
            return;
        }
        if( n<=0 || tar<0) return;
        solve(tar, n-1, cand, res);
        if( cand[n-1] <= tar){
            res.push_back( cand[n-1]);
            solve( tar - cand[n-1] , n, cand, res);
            res.pop_back();
        }
        
    }
public:
    vector<vector<int>> combinationSum(vector<int>& cand, int tar) {
        vector<int> res;
        solve( tar, cand.size(), cand, res);
        return ans;
    }
};