class Solution {
public:
    int maxScore(vector<int>& a, int k) {
        int n=a.size(),ans=0;
        for(int i=1;i<n;i++) a[i]+=a[i-1];
        for(int i=0;i<=k;i++){
            int sum=i>0?a[i-1]:0;
            int req=k-i;
            if(req>0)
            sum+=n-req-1>=0?a[n-1]-a[n-req-1]:a[n-1];
            ans=max(ans,sum);
        }
        return ans;
    }
};