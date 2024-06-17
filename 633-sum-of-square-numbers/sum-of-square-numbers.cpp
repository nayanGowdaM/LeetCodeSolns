class Solution {
public:
    bool judgeSquareSum(int c) {
        for(long long int  i=0;i*i<=c;i++){
            double rem = sqrt( c-i*i);
            if( rem == floor( rem)) return true;
        }
        return false;
    }
};