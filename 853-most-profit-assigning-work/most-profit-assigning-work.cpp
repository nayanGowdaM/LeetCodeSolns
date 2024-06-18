class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>> arr;
        for( int i=0;i<profit.size();i++){
            arr.push_back({ profit[i], difficulty[i]});
        }
        sort( arr.begin(), arr.end());
        sort( worker.begin(), worker.end());
        int j=worker.size()-1, i=profit.size()-1;
        int ans=0;
        while(i>=0 && j>=0){
            if( arr[i].second <= worker[j]){
                ans+= arr[i].first;
                j--;
            }
            else{
                i--;
            }
        }
        return ans;
    }
};