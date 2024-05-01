class Solution {
    bool present( string& a, string& b){
        int i=0, j=0;
        for(;i<a.size() && j<b.size();){
            if( a[i] == b[j]){
                j++;
            }
            i++;
        }
        if(j==b.size() ) return true;
        return false;
    }
public:
    string findLongestWord(string s, vector<string>& dict) {
        string ans;
        for( auto& x: dict){
            if(present(s, x)){
                if( ans.size()<x.size()) ans = x;
                else if( ans.size() == x.size() && x<ans) ans = x;
            }
        }

        return ans;
    }
};