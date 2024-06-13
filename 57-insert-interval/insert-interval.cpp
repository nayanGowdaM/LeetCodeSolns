class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int i=0, n=intervals.size();
        while( i<n && intervals[i][0]<newInterval[0] && intervals[i][1] < newInterval[0]){
            ans.push_back( intervals[i]);
            i++;
        }
        if( i==n) ans.push_back( newInterval);
        else{
            int start = newInterval[0] , end=newInterval[1];
            while( i<n && !(end<intervals[i][0])){
                start= min(start, intervals[i][0]);
                end=max( end, intervals[i][1]);
                i++;
            }
            ans.push_back({start, end});
        }
        while( i<n){
            ans.push_back( intervals[i]);
            i++;
        }
        return ans;
    }
};