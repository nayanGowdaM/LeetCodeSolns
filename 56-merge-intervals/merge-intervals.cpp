class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& slot) {
        sort(slot.begin(), slot.end());
        vector<vector<int>> ans;
        int s = slot[0][0], e = slot[0][1];
        for( int i=1;i<slot.size();i++){
            if( e < slot[i][0]){
                ans.push_back({s,e});
                s=slot[i][0];
                e=slot[i][1];
            }
            else{
                e=max( e, slot[i][1]);
            }
        }
        ans.push_back( {s,e});
        return ans;
    }
};