class Solution {
public:
    int numIdenticalPairs(vector<int>& a) {
        int n=a.size(),ct=0;
        for(int i=0;i<n-1;i++){
            //cout<<i<<" ";
            for(int j=i+1;j<n;j++) 
            if(a[i]==a[j]){cout<<a[j]<<" "; ct++;}
            //cout<<endl;
        }
        
        return ct;
    }
};