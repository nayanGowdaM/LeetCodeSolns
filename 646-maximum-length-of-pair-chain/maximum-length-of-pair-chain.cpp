class Solution {
    static bool cmp( vector<int>& x, vector<int>& y){
        return x[1]<y[1];
    }
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), cmp);
        int prev=INT_MIN;
        int ans=0;
        for( auto& x : pairs){
            if(x[0]> prev){
                prev=x[1];
                ans++;
            }
        }
        return ans;
    }
};