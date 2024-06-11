class Solution {
public:
    double myPow(double x, int n) {
        int signx = true, signy=true;
        if( x<0) signx=false;
        if( n<0) signy=false;
        x=abs( x) ;
        long long int m = abs(  n);
        double ans=1;
        while( m>0){
            if( m%2){
                ans*=x;
                m--;
            }
            else{
                x*=x;
                m/=2;
            }
        }
        if( !signx && !signy){
            if( n%2) return - 1/ans;
            else return 1/ans;
        }
        else if(!signx){
            if( n%2) return -ans;
            else return ans;
        }
        else if( !signy){
            return 1/ans;
        }
        else return ans;

    }
};