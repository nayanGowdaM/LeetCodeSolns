class Solution {
public:
    int countSegments(string s) {
        int n=s.size(),i=0,ans=0;
        while(i<n){
            while(i<n && s[i]==' ') i++;
            if(i>=n) break;
            ans++;
            while(i<n && s[i]!=' ')i++;
        }
        return ans;
    }
};