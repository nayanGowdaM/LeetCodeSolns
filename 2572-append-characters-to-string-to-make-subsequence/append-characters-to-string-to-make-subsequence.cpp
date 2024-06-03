class Solution {
public:
    int appendCharacters(string s, string t) {
        int i=0, m=s.size(), j=0, n=t.size();
        while( i<m && j<n){
            if( s[i]==t[j]){
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        return n-j;

    }
};