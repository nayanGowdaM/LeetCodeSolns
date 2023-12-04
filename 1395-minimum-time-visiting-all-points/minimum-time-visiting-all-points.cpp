class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& p) {
        int n=p.size(),ans=0;
        for(int i=0;i<n-1;i++){
            int x=abs(p[i][0]-p[i+1][0]);
            int y=abs(p[i][1]-p[i+1][1]);
            ans+=min(x,y)+abs(x-y);
        }
        return ans;
    }
};