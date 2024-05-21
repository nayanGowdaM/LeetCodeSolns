class Solution {
public:
    int findPermutationDifference(string s, string t) {
        vector<int> diff( 26,-1);
        int ans=0;
        for( int i=0;i<s.size();i++){
            diff[s[i]-'a'] = i;
        }

        for( int i=0;i<t.size();i++){

            diff[t[i]-'a'] = abs( diff[t[i] -'a'] - i);
            ans += diff[t[i] - 'a'];
        }

        return ans;
    }
};