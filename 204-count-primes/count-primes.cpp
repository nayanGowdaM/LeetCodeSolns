class Solution {
public:
    int countPrimes(int n) {
        if( n<=2) return 0;
        vector<bool> arr( n,true);
        int ct=0;
        arr[0] = arr[1] =false;
        for( int i=2;i<n;i++){
            if( arr[i]){
                for( int j=i+i;j<n;j+=i){
                    arr[j]=false;
                }
            }
        }
        for( auto x: arr) ct+= x==true;
        return ct;
    }
};