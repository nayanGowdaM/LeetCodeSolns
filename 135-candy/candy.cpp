class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int> ans(n);
        ans[0] = 1;
        int ct=1;
        for( int i=1;i<n;i++){
            if( ratings[i]>ratings[i-1]){
                ct++;
            }
            else ct=1;
            ans[i]=( ct);
        }

        for( int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]) ct++;
            else ct=1;
            ans[i] = max( ans[i] , ct);
        }

        return accumulate( ans.begin(), ans.end(), 0);
    }
};