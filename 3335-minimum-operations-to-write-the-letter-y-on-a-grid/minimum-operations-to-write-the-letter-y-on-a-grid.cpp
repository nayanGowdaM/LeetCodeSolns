class Solution {
public:
    int minimumOperationsToWriteY(vector<vector<int>>& a) {
        int n=a.size();
        unordered_map<int,int> mpy,mpn;
        for( int i=0;i<n/2;i++){
            mpy[a[i][i]]++;
            mpy[a[i][n-1-i]]++;
            
        }
        for(int i=n/2;i<n;i++) mpy[a[i][n/2]]++;
        
        for(int i=0;i<n;i++) for(int  j=0;j<n;j++) mpn[a[i][j]]++;
        mpn[0]=mpn[0]-mpy[0];
        mpn[1]=mpn[1]-mpy[1];
        mpn[2]=mpn[2]-mpy[2];
        int m=(3*n-1)/2;
        int ans=INT_MAX;
        ans = min( ans,  -mpy[0] + n*n - max(mpn[1],mpn[2] ));
        ans = min( ans,  -mpy[1] + n*n - max(mpn[0],mpn[2] ));
        ans = min( ans,  -mpy[2] + n*n - max(mpn[1],mpn[0] ));
        return ans;
    }
};