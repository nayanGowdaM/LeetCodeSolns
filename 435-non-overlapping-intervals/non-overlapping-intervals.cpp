class Solution {
static bool cmp(vector<int> &a,vector<int> &b) {
	return a[1]<b[1];
}
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort( intervals.begin(), intervals.end(),cmp);
        // for( auto x: intervals) cout<<x[0] <<" "<<x[1]<<endl;
        int ans=0, prevEnd=-50000;
        for( int i=0;i<intervals.size();i++){
            if( intervals[i][0]>=prevEnd){
                ans++;
                prevEnd=intervals[i][1];
            }
        }
        return intervals.size()-ans;
    }
};