class Solution {
public:
    int maxDepth(string s) {
        int ans=0;
        stack<char>st;
        for( int i=0;i<s.size();i++){
            if( s[i]=='('){
                st.push('(');
                if( st.size()>ans) ans = st.size();
            }
            else if( s[i]==')'){
                st.pop();
            }
        }
        return ans;
    }
};