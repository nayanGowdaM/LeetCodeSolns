class Solution {
    vector<vector<string>> ans;
    
    bool isPal( string& s, int i, int j){
        while( i<j){
            if( s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    void solve( string& s, int n, vector<string>& res , vector<vector<bool>>& dp){
        if( n==s.size()){
            ans.push_back(res);
            return;
        }
        for( int i=n+1;i<=s.size();i++){
            if( dp[n][i-1]){
                res.push_back(s.substr( n, i-n));
                solve( s, i, res, dp);
                res.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<string>res;
        int n=s.size();
        vector<vector<bool>> dp( n, vector<bool>(n,false));
        for( int i=n-1;i>=0 ;i--){
            for(int j=i;j<n;j++){
                if( s[i]==s[j]){
                    if( j-i <= 2) dp[i][j] = true;
                    else dp[i][j] = dp[i+1][j-1];
                }
                else dp[i][j]=false;
                
            }
        }
        solve( s, 0, res, dp);
        return ans;
    }
};