class Solution {
    vector<vector<int>> ans;

    void solve( int tar, int k , int n, vector<int>& res){
        if( k==0 && tar == 0){
            ans.push_back( res);
            return ;
        }


       

        if( n <= tar && k>0 && n>0){
            res.push_back( n);
            solve( tar-n, k-1, n-1, res);
            res.pop_back();
        }

        if( n>0)
         solve( tar, k, n-1 , res);
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        if( n > 45) return ans;
        vector<int> res;
        solve( n, k, 9, res);
        return ans;
    }
};