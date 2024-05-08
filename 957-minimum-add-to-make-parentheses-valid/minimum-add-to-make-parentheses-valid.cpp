class Solution {
public:
    int minAddToMakeValid(string s) {
        int ct=0;
        stack<char> st;
        for( auto x: s){
            if( x=='('){
                st.push(x);

            }
            else{
                if( st.empty())  ct++;
                else st.pop();
            }

        }
        return ct+st.size();
    }
};