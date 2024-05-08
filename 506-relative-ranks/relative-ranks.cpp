class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        map<int , int > mp;
        int n=score.size();
        for( int i=0;i<n;i++){
            mp[score[i]] = i;
        }

        vector<string> ans( n);
        for( auto it = mp.begin();it!=mp.end();it++){
            int place =n - distance( mp.begin(), it);
            // ans[it->second] = to_string( place);
            if( place==1) ans[it->second] = "Gold Medal";
            else if( place == 2) ans[it->second] = "Silver Medal";
            else if( place == 3) ans[it->second] = "Bronze Medal";
            else ans[it->second] = to_string( place);
        }
        return ans;
    }
};