class Solution {
public:
    int maxScore(vector<int>& a, int k) {
        int n=a.size(),i=0,j=n-k-1,ind=0;
        int x=accumulate(a.begin(),a.end()-k,0);
        int sum=x;
        j++;
        while(j<n){
            sum+=a[j]-a[i];
            if(x>sum){ x=sum; ind=i;}
            i++;
            j++;
        }
        int ans=accumulate(a.begin(),a.end(),0)-x;
        return ans;
    }
};