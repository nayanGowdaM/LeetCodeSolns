class Solution {
public:
    string makeGood(string s) {
        stack<char>st;
        for( int i=0;i<s.size();i++){
            if(st.empty() || (( s[i]-'A' != st.top()-'a') &&( s[i]-'a' != st.top()-'A')) ) st.push(s[i]);
            else st.pop();
        } 
        string str="";
        while(!st.empty()){
            str.push_back( st.top());
            st.pop();
        }
        reverse( str.begin(), str.end());
        return str;
    }
};