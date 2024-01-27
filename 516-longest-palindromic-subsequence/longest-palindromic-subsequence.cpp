class Solution {
public:
    int longestPalindromeSubseq(string a) {
        string b=a;
        reverse(b.begin(),b.end());
        int m=a.size(), n=b.size();
        // vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        vector<int> prev(n+1,0),cur(n+1,0);
        // for(int i=0;i<=m;i++)  cur[0]=0;
        for(int i=0;i<=n;i++) prev[i]=0;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(a[i-1]==b[j-1] ) cur[j] = 1 +prev[j-1];
                else cur[j] =  max(prev[j] , cur[j-1]);
            }
            prev=cur;
        }
        return cur[n];
    }
};