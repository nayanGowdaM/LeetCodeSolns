class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> res( n, 0);
        if( k==0) return res;
        int start = 1, end = k;
        if( k<0){
            k*=-1;
            start = n-k;
            end = n-1;
        }
        int kSum = 0;
        for( int i=start;i<=end;i++) kSum += code[i] ;
        for(int i=0;i<n;i++){
            res[i] = kSum;
            kSum -= code[(start++)%n];
            kSum += code[( ++end )%n];
        }
        return res;
    }
};