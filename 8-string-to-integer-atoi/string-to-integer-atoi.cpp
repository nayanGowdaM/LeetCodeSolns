class Solution {
    void solve( int i  , int d, string& s, string& ans){
        if(i==s.size()) return ;
        if(d && (s[i]<'0' || s[i]>'9'))  return ;
        if(s[i]>='0' && s[i]<='9' ){
            ans.push_back(s[i]);
            return solve( i+1,1,s, ans);
        }
        if(s[i]==' ')return solve(i+1, d, s, ans);
        if(s[i]=='+' || s[i] == '-'){
            ans.push_back(s[i]);
            return solve(i+1,1,s,ans);
        }
        else return ;
    }

public:
    int myAtoi(string s) {
        string ans="";
        solve(0,0,s,ans);
        long long res=0;
        int i=0,flag =1;
        if(ans[0]=='+'|| ans[0]=='-'){
            i=1;
            flag=(ans[0]=='+')?1:-1;
        }
        for(;i<ans.size();i++){
            res = res*10 + ans[i]-'0';
            if(res>INT_MAX && flag == 1 ) return INT_MAX;
            else if( res>INT_MAX+(long long)1 && flag == -1) return INT_MIN;
        }
        cout<<ans;
        return flag*res;
    }
};