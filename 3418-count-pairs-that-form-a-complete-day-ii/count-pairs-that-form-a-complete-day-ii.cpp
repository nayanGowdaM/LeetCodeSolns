class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        vector<int> hrs( 24,0);
        long long  ans=0;
        for( int i=0;i<hours.size(); i++){
            ans+= hrs[hours[i]%24];
            int idx= 24 - ( hours[i] % 24);
            cout<<idx<<" ";
            hrs[(24 - ( hours[i] %24))%24]++;
        }
        return ans;
    
    }
};