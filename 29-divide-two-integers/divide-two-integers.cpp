class Solution {
public:
    int divide(int a, int b) {
        long long dividend = a, divisor = b;
        bool flag = false; 
        if(( divisor<0 && dividend>0) || ( divisor>0 && dividend<0)) flag = true;
        dividend = abs( a);
        divisor = abs(b);
        long long int i=31,ans=0;
        for( ;i>=0;i--){
            if( dividend >= divisor*( 1LL<<i)) break;
        }

        while( dividend>=divisor){
            if( dividend >= divisor*( 1LL<<i)){
                dividend -= divisor * ( 1LL<<i);
                ans+= (1LL<<i);
            }
            i--;
        }
        if(ans>INT_MAX){
            return flag ? INT_MIN :INT_MAX;
        }
        return flag?-ans:ans;
    }
};