class Solution {
public:
    int maxSubArray(vector<int>& a) {
        int m=INT_MIN,sum=0,n=a.size();
        for(int i=0;i<n;i++) {
            sum+=a[i];
            if(sum>m) m=sum;
            if(sum<0) sum=0;

        }
        return m;
    }
};