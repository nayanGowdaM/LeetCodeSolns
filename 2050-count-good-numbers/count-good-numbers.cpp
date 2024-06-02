class Solution {
     int M = 1e9+7;

     int pow( long long  x, long long n){
        // cout<<x<<" "<<n<<endl;
        if( n==0) return 1;
        // long long y = pow( x*x, n/2);
        if( n%2) return (x*pow( x+0ll, n-1))%M;
        else return pow(  (x*1ll *x)%M, n/2)%M;
     }
public:
    int countGoodNumbers(long long n) {
        int even = pow( 5, n/2 + n%2), odd=pow( 4, floor(n/2));
        // cout<<even<<" "<<odd;
        return ( 1LL * even * odd)%M;
    }
};