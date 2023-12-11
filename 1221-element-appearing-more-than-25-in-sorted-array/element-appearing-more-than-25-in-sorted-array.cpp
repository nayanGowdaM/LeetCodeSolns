class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        if(arr.size()==1 ) return arr[0];
        int n=arr.size(),k=n/4;
        while(k*4<=n) k++;
        // cout<<k;
        for(int i=0;i<n;){
            int x=arr[i],j=i+1;
            // cout<<i<<" "<<j<<endl;
            while(j<n && x==arr[j] ){
                // cout<<" "<<j-i+1;
                if((j-i+1)>=k) return x;
                j++;
                
            }
            i=j;
        }
        return -1;
    }
};