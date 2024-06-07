class Solution {
public:
    bool isPowerOfTwo(int n) {
        if( n== 0) return false;
        long long int temp = ( 1LL * n) & ( 1LL*(n - 1LL ));
        cout<<temp;
        if( temp==0) return true;
        else return false;
    }
};