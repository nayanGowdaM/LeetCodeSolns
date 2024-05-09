class Solution {
    static bool cmp( int& a, int& b){
        return a>b;
    }
public:
    long long maximumHappinessSum(vector<int>& happy, int k) {
        sort(happy.begin(), happy.end() , cmp );
        long long  ans=0;
        for( int i=0;i<k;i++){
            ans += max( happy[i]-i, 0);
        }
        return ans;
    }
};