class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>lastindex(256,-1);
        int n=s.size(),m=0;
        for(int l=0,r=0;r<n;r++){
            l=max(l,lastindex[s[r]]+1);
            lastindex[s[r]]=r;
            m=max(m,r-l+1);
        }
        return m;
    }
};