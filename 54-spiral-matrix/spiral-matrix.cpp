class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& a) {
        int l=0, r=a[0].size()-1, t=0, b=a.size()-1, dir=0;
        vector<int> ans;
        while( l<=r && t<=b){
            switch( dir){
                case 0:
                    for( int i=l;i<=r;i++) ans.push_back( a[t][i]);
                    t++;
                    dir = (dir+1) % 4;
                    break;
                case 1:
                    for( int i=t;i<=b;i++) ans.push_back( a[i][r]);
                    r--;
                    dir=(dir+1)%4;
                    break;
                case 2:
                    for( int i=r;i>=l;i--) ans.push_back( a[b][i]);
                    b--;
                    dir = (dir+1) % 4;
                    break;   
                case 3:
                    for( int i=b;i>=t;i--) ans.push_back( a[i][l]);
                    l++;
                    dir = (dir+1) % 4;
                    break;
            }
        }
        if(l<=r){
            switch( dir){
                case 0:
                    for( int i=l;i<=r;i++) ans.push_back( a[t][i]);
                    t++;
                    dir = (dir+1) % 4;
                    break;
                case 1:
                    for( int i=t;i<=b;i++) ans.push_back( a[i][r]);
                    r--;
                    dir=(dir+1)%4;
                    break;
                case 2:
                    for( int i=r;i>=l;i--) ans.push_back( a[b][i]);
                    b--;
                    dir = (dir+1) % 4;
                    break;   
                case 3:
                    for( int i=b;i>=t;i--) ans.push_back( a[i][l]);
                    l++;
                    dir = (dir+1) % 4;
                    break;
            }
        }
        if( t<=b){
            switch( dir){
                case 0:
                    for( int i=l;i<=r;i++) ans.push_back( a[t][i]);
                    t++;
                    dir = (dir+1) % 4;
                    break;
                case 1:
                    for( int i=t;i<=b;i++) ans.push_back( a[i][r]);
                    r--;
                    dir=(dir+1)%4;
                    break;
                case 2:
                    for( int i=r;i>=l;i--) ans.push_back( a[b][i]);
                    b--;
                    dir = (dir+1) % 4;
                    break;   
                case 3:
                    for( int i=b;i>=t;i--) ans.push_back( a[i][l]);
                    l++;
                    dir = (dir+1) % 4;
                    break;
            }
        }
        return ans;
    }
};