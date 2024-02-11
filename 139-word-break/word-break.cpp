int dp[302][302];

class Solution {
    bool solve( int idx, int n, string& s, vector<string>& dict){
        if( idx==-1) return n==1? true: false;
        if( dp[idx][n]!=-1) return dp[idx][n];
        bool x = solve( idx-1,n+1, s,dict), y=false ;
        if( find( dict.begin(),dict.end(), s.substr(idx, n))!=dict.end()) 
        y= solve(  idx-1,1,s,dict);
        return dp[idx][n] = x||y;
    }
public:
    bool wordBreak(string s, vector<string>& dict) {
        memset(  dp, -1, sizeof(dp));
        return solve( s.size()-1, 1,s, dict);
    }
};