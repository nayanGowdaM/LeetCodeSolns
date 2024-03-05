class Solution {
public:
    int minimumLength(string s) {
        int pre=-1, suff=s.size(), n=s.size();
        while( pre<suff){
            if(s[pre+1] == s[suff-1]){
                if(pre+1 == suff-1) return 1;
                else{
                    char temp=s[pre+1];
                    pre++;
                    while(pre< n-1 && temp==s[pre+1]) pre++;
                    suff--;
                    while(suff>0 &&  temp==s[suff-1]) suff--;

                    if( pre>suff) return 0;
                }
            }
            else return suff-pre-1;
        }
        return 1;
    }
};