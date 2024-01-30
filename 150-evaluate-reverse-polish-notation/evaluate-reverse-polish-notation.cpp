class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto& x: tokens){
            int ans;
            if(x=="+"|| x=="-" || x=="*" || x=="/"){
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                
                switch(x[0]){
                    case '+': ans=b+a; break;
                    case '-': ans=b-a; break;
                    case '*': ans=b*a; break;
                    case '/': ans=b/a; break;
                }
                
            }
            else{
                ans=stoi(x);
            }
            st.push(ans);
        }
        return st.top();
    }
};