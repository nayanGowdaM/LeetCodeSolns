class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size(), n=image[0].size(), prevC = image[sr][sc];
        if ( prevC == color) return image;
        queue<pair<int,int>> q;
        q.push({sr,sc});
        vector<vector<int>> dir = {{ 0,1},{0,-1}, {1,0},{-1,0}};
        image[sr][sc] = color;
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            for( int i=0;i<4;i++){
                int x = node.first + dir[i][0] , y = node.second + dir[i][1];
                if( x>=0 && y>=0 && x<m && y<n && image[x][y]==prevC){
                    q.push({x,y});
                    image[x][y] = color;
                }
            
            }
            
        }
        return image;
    }
};