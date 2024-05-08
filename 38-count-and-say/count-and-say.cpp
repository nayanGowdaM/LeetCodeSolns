class Solution {
    string solve( string& s){
        string ans;
        for( int i=0;i<s.size();){
            char x = s[i];
            int start = i;
            while( s[i]==x) i++;
            ans.push_back( (char)(i-start + '0'));
            ans.push_back(x);
        }
        return ans;
    }
public:
    string countAndSay(int n) {
        string ans = "1";
        for( int i=2;i<=n;i++){
            ans = solve( ans);
        }
        return ans;
    }
};