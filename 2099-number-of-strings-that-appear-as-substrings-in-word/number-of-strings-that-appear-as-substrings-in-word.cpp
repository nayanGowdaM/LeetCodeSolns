class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int ans=0;
        for( auto x: patterns ){
            ans += ( word.find(x)!=string::npos);
        }
        return ans;
    }
};