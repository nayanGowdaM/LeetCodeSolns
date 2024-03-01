class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int ct=0;
        int n=s.size();
        for(auto x: s) if(x=='1') ct++;
        string ans(n,'0');
        ct--;
        ans[n-1]='1';
        int i=0;
        while(ct--) ans[i++] = '1';
        return ans;
    }
};