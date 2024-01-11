class Solution {
    // string fun(string s1,string s2, int x, int y ){
    //     if(x==0) return s2.substr(0,y);
    //     if(y==0) return s1.substr(0,x);
    //     if(s1[x-1]==s2[y-1]){
    //         return s1[x-1]+fun(s1,s2,x-1,y-1);
    //     }
    //     else{
    //         string res1=fun(s1,s2,x-1,y);
    //         string res2=fun(s1,s2,x,y-1);
    //         return res1.size()<res2.size()? s1[x-1]+res1 : s2[y-1]+res2; 
    //     }
    // }
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m=str1.size(),n=str2.size();
        int dp[m+1][n+1];

        for (int i=0;i<=m;i++) dp[i][0]=i;
        for(int i=0;i<=n;i++) dp[0][i]=i;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(str1[i-1]==str2[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=min(dp[i-1][j],dp[i][j-1])+1;
            }
        }
        int i=m,j=n;
        string ans;
        while(i>0 && j>0) {
            if(str1[i-1]==str2[j-1]){
                ans.push_back(str1[i-1]);
                i--;
                j--;
            }
            else{
                if(dp[i-1][j]> dp[i][j-1]){
                    ans.push_back(str2[j-1]);
                    j--;
                }
                else{
                    ans.push_back(str1[i-1]);
                    i--;
                }
            }
        }
        while(i>0) ans.push_back(str1[--i]);
        while(j>0) ans.push_back(str2[--j]);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};