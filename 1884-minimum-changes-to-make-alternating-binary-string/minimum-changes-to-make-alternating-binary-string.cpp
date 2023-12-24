class Solution {
public:
    int minOperations(string s) {
        char z='0',o='1';
        int ct1=0,ct2=0;
        for(int i=0;i<s.size();i++){
            if(i%2){
                if(s[i]!=o) ct1++;
            }
            else{
                if(s[i]!=z) ct1++;
            }
        }
        ct2=s.size()-ct1;
        return min(ct1,ct2);
    }
};