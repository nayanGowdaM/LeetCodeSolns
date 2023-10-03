class Solution {
public:
    bool isMonotonic(vector<int>& a) {
        int n=a.size(),i=1;
        if(n<3) return true;
        if(a[0]<a[n-1]){
            while(i<n && a[i-1]<=a[i]) i++;
            return i==n;
        }
        else if(a[0]>a[n-1]){
            while(i<n && a[i-1]>=a[i]) i++;
            return i==n;
        }
        else{
            while(i<n && a[i-1]==a[i]) i++;
            return i==n;
        }
        
    }
};