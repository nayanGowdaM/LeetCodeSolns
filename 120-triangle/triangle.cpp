class Solution {
public:
    int minimumTotal(vector<vector<int>>& a) {
        int m=a.size();
        for(int i=m-2;i>=0;i--){
            for(int j=0;j<=i;j++){
                a[i][j]=a[i][j]+min(a[i+1][j],a[i+1][j+1]);
            }
        }
        return a[0][0];

    }
};