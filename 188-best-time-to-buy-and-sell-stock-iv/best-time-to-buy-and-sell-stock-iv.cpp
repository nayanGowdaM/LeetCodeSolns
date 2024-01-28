class Solution {
public:
    int maxProfit(int Cap, vector<int>& st) {
        int n=st.size();
        // vector<vector<vector<int>>> dp(n+1,vector<vector<int>>( 2,vector<int > (3,0)));
        vector<vector<int>> cur(2,vector<int > (Cap+1,0)),next(2,vector<int > (Cap+1,0));
        for(int i=n-1; i>=0;i--){
            for( int j=0;j<2;j++){
                for( int k=1;k<=Cap;k++){
                    int profit;
                    if(!j){
                        profit = max( -st[i] + next[!j][k] , next[j][k]);
                    }
                    else profit = max( st[i] + next[!j][k-1], next[j][k]);
                    cur[j][k]=profit;
                }
            }
            next=cur;
        }
        return cur[0][Cap];
    }
};