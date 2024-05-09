class Solution {
    int dp[302][302];
    bool present( string s, vector<string>& dict){
        auto it = lower_bound( dict.begin(), dict.end(), s);
        if( it== dict.end()) return false;
        else return *it==s;
    }

    bool solve( string& s, int start, int end, vector<string>& dict){
        if( start == s.size()) return true;
        if( end == s.size() ) return false;
        if(dp[start][end] != -1) return dp[start][end];
        // cout<<start<<" "<<end<<endl;

        if(  present(s.substr( start , end-start+1) , dict )  && solve(s, end+1, end+1, dict)) return dp[start][end] = 1;
        if(solve( s, start, end+1, dict) ) return dp[start][end] = true;
        return dp[start][end] = 0;
    }
public:
    bool wordBreak(string s, vector<string>& dict) {
        memset(dp,-1, sizeof(dp) );
        sort( dict.begin(), dict.end());
        return solve( s, 0,0,dict);
    }
};