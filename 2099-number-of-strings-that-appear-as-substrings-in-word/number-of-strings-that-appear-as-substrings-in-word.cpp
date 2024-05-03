class Solution {
    int isSubstring(string& s1, string& s2)
{
    // using find method to check if s1 is
    // a substring of s2
    if (s2.find(s1) != string::npos)
        return s2.find(s1);
    return -1;
}
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int ans = 0;
        for( auto x: patterns){
            ans += ( isSubstring(x, word)!=-1);
        }
        return ans;
    }
};