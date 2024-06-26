class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> expected( heights.begin(), heights.end());
        sort( heights.begin(), heights.end());
        int ct = 0;
        for(int i=0;i<heights.size();i++){
            if( heights[i] != expected[i]) ct++;
        }
        return ct;
    }
};