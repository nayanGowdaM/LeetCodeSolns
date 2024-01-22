class Solution {
    int dp[102][102];
    int path(vector<vector<int>>& a,int i,int j){
        if(i==0 && j==0 ) return 0;
        if(i==0 && j==1 || i==1 && j==0) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int ct1=0,ct2=0;
        if(i>0 && !a[i-1][j]) ct1=path(a,i-1,j);
        if(j>0 && !a[i][j-1]) ct2=path(a,i,j-1);
        return dp[i][j]=ct1+ct2;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& a) {
        int i=a.size()-1,j=a[0].size()-1;
        if(i==0 && j==0) return !a[i][j];
        if(a[i][j]  || a[0][0]) return 0;
        // if(i==0 || j==0) return 1;
        memset(dp,-1,sizeof(dp));
        return path(a,i,j);
    }
};