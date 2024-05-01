class Solution {
public:
    string generateTheString(int n) {
        string ans="";
        if( n%2==0){
            ans.push_back('a');
            n--;
        }
        for( int i=0;i<n;i++) ans.push_back('b');
        return ans;
    }
};