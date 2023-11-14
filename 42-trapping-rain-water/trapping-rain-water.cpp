class Solution {
public:
    int trap(vector<int>& a) {
        int n=a.size(),l=0,r=n-1,ml=0,mr=0,ans=0;
        while(l<=r){
            if(a[l]<=a[r]){
                if(a[l]>=ml){
                    ml=a[l];
                }
                else{
                    ans+=ml-a[l];
                }
                l++;
            }
            else{
                if(a[r]>=mr){
                    mr=a[r];
                }
                else 
                ans+=mr-a[r];
                r--;
            }
        }
        return ans;
    }
};