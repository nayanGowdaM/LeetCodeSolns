class Solution {
public:
    bool isValid(string& num,int l, int j){
        int i=l;
        while(i<=j){
            if(num[i]!=num[j]) return false;
            i++;
        } 
        return true;
    }
    string largestGoodInteger(string num) {
        int i=0,j=2,n=num.size(),x=-1;
        while(j<n){
            if(isValid(num, i, j)){
                x=max(x,num[i]-'0');
                i=j;
            }
            i++;
            j=i+2;
            
        }
        string ans="";
        if(x==-1) return ans;
        ans+=to_string(x)+to_string(x)+to_string(x);
        return ans;
    }
};