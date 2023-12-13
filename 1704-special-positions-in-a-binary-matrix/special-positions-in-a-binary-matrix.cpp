class Solution {
public:
    bool check(vector<vector<int>>& a, int i, int j){
        int x=0,y=0;
        for(int p=0;p<a.size();p++){
            if(p!=i && a[p][j]) return false;
        }
        for(int p=0;p<a[0].size();p++){
            if(p!=j & a[i][p]) return false;
        }
        return true;
    }
    int numSpecial(vector<vector<int>>& mat) {
        int ct=0;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j] && check(mat,i,j) ) ct++;
            }
        }
        return ct;
    }
};