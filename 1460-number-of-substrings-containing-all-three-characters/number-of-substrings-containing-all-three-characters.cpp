class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        vector<int> v(3,0);
        int i=0,j=0,ct=0;
        while(i<n && j<=n){
            while( !( v[0] && v[1] && v[2]) && j<n) v[s[j++]-'a']++;
            if(!( v[0] && v[1] && v[2]) && j==n) break;
            ct+=n-j+1;
            v[s[i]-'a']--;
            i++;
        }
        return ct;
    }
};