class Solution {
public:
    int maxSatisfied(vector<int>& cust, vector<int>& grumpy, int min) {
        int ans=0, res=0;
        int n=cust.size();
        for( int i=0;i<n;i++){
            if(!grumpy[i]) ans+=cust[i];
        }
        int start =0, end = min-1, temp=0;
        for( int  i=start;i<=end;i++){
            if(grumpy[i]) temp+=cust[i];
        }

        ans = ans + temp;
        while( end< n){
            res = max( res, ans);
            if( grumpy[start]) ans -= cust[start];
            start++;
            end++;
            if(end<n  && grumpy[end]) ans += cust[end];
        }
        return res;
        
    }
};