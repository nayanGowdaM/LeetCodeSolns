class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for( auto x: s){
            if( x=='(' || x=='{' || x=='[') st.push( x);
            else{
                switch( x){
                    case ')': 
                        if(!st.empty() &&  st.top() == '(') st.pop();
                        else return false;
                        break;
                    case '}' :
                        if(!st.empty() &&  st.top() =='{') st.pop();
                        else return false;
                        break;
                    case ']':
                        if(!st.empty() &&  st.top() == '[') st.pop();
                        else return false;
                        break;
                }
            }
        }
        return st.empty();
    }
};