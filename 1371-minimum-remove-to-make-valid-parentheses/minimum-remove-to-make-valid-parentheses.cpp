class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int open=0, closed=0;
        for( int i=0;i<s.size();i++){
            if(s[i]=='('){
                open++;
            }
            else if( s[i]==')'){
                if(open) open--;
                else closed++;
            }
        }
        string str = "";
        for(auto x : s){
            if(x==')'){
                if(closed) closed--;
                else str.push_back(')');
            }
            else str.push_back(x);
        }
        cout<<str;
        s=str;
        str="";
        for( int i=s.size()-1;i>=0;i--){
            if(s[i]=='('){
                if(open) open--;
                else str.push_back('(');
            }
            else str.push_back(s[i]);
        }
        reverse(str.begin(), str.end());
        return str;
    }
};