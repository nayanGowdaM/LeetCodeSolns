class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int x=tickets[k], ans=0;
        for( int i=0;i<=k;i++) ans += min( tickets[i], x);
        for( int i=k+1;i<tickets.size();i++) ans += min( tickets[i], x-1);
        return ans;
        
    }
};