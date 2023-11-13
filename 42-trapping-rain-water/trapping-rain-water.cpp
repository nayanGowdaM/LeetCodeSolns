class Solution {
public:
    int trap(vector<int>& a) {
        int n=a.size(),ans=0,m=-1;
        vector<int> left(n,-1),right(n,-1),arr(n);
        for(int i=0;i<n;i++){
            if(a[i]>m){
                left[i]=-1;
                m=a[i];
            }
            else left[i]=m;
        }
        m=-1;
        for(int i=n-1;i>=0;i--){
            if(a[i]>m){
                right[i]=-1;
                m=a[i];
            }
            else right[i]=m;
        }
        for(int i=0;i<n;i++) arr[i]=min(left[i],right[i]);
        for(int i=0;i<n;i++){
            if(arr[i]!=-1){
                ans+=arr[i]-a[i];
            }
        }
        return ans;
    }
};