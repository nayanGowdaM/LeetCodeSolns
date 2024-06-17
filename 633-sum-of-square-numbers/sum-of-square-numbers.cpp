class Solution {
public:
    bool judgeSquareSum(int c) {
        long long  i=0;
        unordered_set<long long int > st;
        for(;i*i<=c/2;i++){
            st.insert( i*1LL*i);
        }
        i--;
        for(;i*i<=c;i++ ){
            if( st.find( c-i*i) != st.end()) return true;

        }
        return false;
    }
};