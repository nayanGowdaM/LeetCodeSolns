class Solution {
    int dp[102];
    bool isValid(string& s, int i, int n){
        if(n==1) return  s[i]!='0';
        else{
            int number = stoi( s.substr(i, 2));
            return number>9 && number<27;
        }
    }
    int solve( string& s, int n){
        if(n>=s.size()) return 1;
        if(dp[n]!=-1) return dp[n];
        int ct1=0, ct2=0;
        if(isValid(s, n,1)){
            ct1 =  solve(s, n+1);
            if(isValid(s, n, 2)){
                ct2=solve(s,n+2);
            }
            return dp[n]= ct1+ct2;
        }
        else return dp[n]= 0;
    }
public:
    int numDecodings(string s) {
        memset(dp,-1,sizeof(dp));
        return solve( s, 0);
    }
};