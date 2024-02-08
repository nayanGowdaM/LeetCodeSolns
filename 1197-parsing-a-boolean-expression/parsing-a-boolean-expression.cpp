class Solution {
public:
    bool parseBoolExpr(string s) {
        stack<char>st , o;
        for(auto& x: s){
            if(x=='t' || x=='f' || x=='(')o.push(x);
            else if( x=='!' || x=='|' || x=='&') st.push(x);
            else if( x==')'){
                char symbol = st.top();
                st.pop();
                if(symbol == '!'){
                    char nots= o.top();
                    o.pop();
                    o.pop();
                    if( nots=='t' ) o.push('f');
                    else o.push('t');
                }
                else{
                    if(symbol=='|'){
                        char ors='f';
                        while( o.top()!='('){
                            if( o.top()=='t') ors='t';
                            o.pop();
                        }
                        o.pop();
                        o.push(ors);
                    }
                    else{
                        char ands='t';
                        while( o.top()!='('){
                            if( o.top()=='f') ands='f';
                            o.pop();
                        }
                        o.pop();
                        o.push(ands);

                    }
                }
            }
        }
        return o.top()=='t';
    }
};