class Solution {
public:
    bool checkValidString(string s) {
        int pair=0, star=0;
        for( auto x: s){
            if(x=='(') pair++;
            else if(x==')') pair--;
            else star++;

            if(pair+star <0)return 0;
        }
        if( pair<=star){
            pair=star=0;
            for( int i=s.size()-1;i>=0;i--){
                if(s[i]=='(') pair--;
                else if(s[i]==')') pair++;
                else star++;

                if(pair+star <0)return 0;
            }
            return pair<=star;
        }
        else return false;
    }
};