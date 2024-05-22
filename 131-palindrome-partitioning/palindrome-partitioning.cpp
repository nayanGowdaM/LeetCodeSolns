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

    void solve( string& s, int n, vector<string>& res){
        if( n==s.size()){
            ans.push_back(res);
            return;
        }
        for( int i=n+1;i<=s.size();i++){
            if( isPal( s, n, i-1)){
                res.push_back(s.substr( n, i-n));
                solve( s, i, res);
                res.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<string>res;
        solve( s, 0, res);
        return ans;
    }
};