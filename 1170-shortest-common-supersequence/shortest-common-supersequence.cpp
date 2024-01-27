class Solution {
    string solve(string& a, string& b, int m, int n){
        if(m==0)  return b.substr(0,n);
        if(n==0) return a.substr(0,m);
        if(a[m-1]==b[n-1]){
            return a[m-1]+solve(a,b,m-1,n-1);
        }
        else{
            string s1=a[m-1] + solve(a,b,m-1,n);
            string s2=b[n-1]+ solve(a,b,m,n-1);
            return s1.size()>s2.size() ? s2:s1;
        }
    }
public:
    string shortestCommonSupersequence(string a, string b) {
        // return solve(str1,str2,str1.size(),str2.size());

        int m=a.size(), n=b.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        for(int i=0;i<=m;i++) dp[i][0]=i;
        for(int i=0;i<=n;i++) dp[0][i]=i;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(a[i-1]==b[j-1]) dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + 1;
            }
        }

        string s="";
        int i=m,j=n;
        while(i>0 && j>0){
            if(a[i-1] == b[j-1]) {
                s+=a[i-1];
                i--;
                j--;
            }
            else {
                if(dp[i-1][j] > dp[i][j-1]) {
                    s+=b[j-1];
                    j--;
                }
                else{
                    s+=a[i-1];
                    i--;
                }
            }
        }
        while(i>0){
            s+=a[i-1];
            i--;

        }
        while(j>0) {
            s+=b[j-1];
            j--;
        }
        
        reverse(s.begin(),s.end());
        return s;
    }
};