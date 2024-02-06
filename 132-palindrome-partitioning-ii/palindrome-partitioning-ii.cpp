int dp[2002][2002];

class Solution {

    bool isPal( int i, int j, string& s){
        while( i<j){
            if(s[i] == s[j]){
                i++;
                j--;
            }
            else return false;
        }
        return true;
    }

    int solve( int i , int j, string& s){
        if(dp[i][j]!=-1) return dp[i][j];
        if(i==j || isPal(i,j, s)) return dp[i][j]=0;
        int ans=INT_MAX;
        for( int k=i;k<j;k++){
            if( isPal( i, k,s)){
                ans = min( ans, 1+ solve( k+1,j,s));
            }
        }
        return dp[i][j] = ans;
    }
public:
    int minCut(string& s) {
        memset(dp, -1, sizeof(dp));
        return solve( 0, s.size()-1,s);
    }
};