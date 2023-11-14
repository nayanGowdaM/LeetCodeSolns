class Solution {
public:
    int countSegments(string s) {
        int n=s.size(),ans=0;
        if(n==0) return 0;
        for(int i=1;i<n;i++){
            if(s[i-1]==' ' && s[i]!=' ') ans++;
        }
        if(s[0]==' ') return ans;
        else return ans+1;
    }
};