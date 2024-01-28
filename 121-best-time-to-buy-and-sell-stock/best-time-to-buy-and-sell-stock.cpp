class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        int n=prices.size();
        vector<int> sp(prices.begin(),prices.end());
        for(int i=n-2;i>=0;i--) sp[i] = max(sp[i],sp[i+1]);
        for(int i=0 ; i<n-1;i++){
            int temp=sp[i+1];
            
            ans=max(ans,temp - prices[i] );
            // cout<<
        }
        return ans;
    }
};