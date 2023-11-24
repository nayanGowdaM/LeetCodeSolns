class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int ct=0;
        for(int i=s.size()-1,j=g.size()-1;i>=0&&j>=0;){
            if(s[i]>=g[j] ){
                ct++;
                i--;
                j--;
            }else{
                j--;
            }
        }
        return ct;
    }
};