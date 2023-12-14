class Solution {
    int sum(vector<vector<int>>& a, int r, int c){
        int ans=0;
        for(int i=0;i<a[0].size();i++){
            if(a[r][i]) ans++;
            else ans--;
        }
        for(int i=0;i<a.size();i++){
            if(a[i][c]) ans++;
            else ans--;
        }

        return ans;
    }
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& a) {
        int m=a.size(), n=a[0].size();
        vector<int> row(m),col(n);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                row[i]+=a[i][j];
                col[j]+=a[i][j];
            }
        }
        vector<vector<int>>ans(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans[i][j]=2*(row[i]+col[j])-(m+n);
            }
        }
        return ans;
    }
}; 