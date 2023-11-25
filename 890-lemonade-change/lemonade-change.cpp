class Solution {
public:
    vector<int>v;
    bool change(int n){
        int i=20;
        while(n>0){
            if(i<5) return false;
            if(v[i]>0 && n>=i){
                n-=i;
                v[i]--;
            }
            else i/=2;
        }
        return true;
    }
    bool lemonadeChange(vector<int>& bills) {
        for(int i=0;i<=25;i++) v.push_back(0);
        for(auto x: bills){
            int temp=x;
            v[x]++;
            if(x!=5){
                if(!change(x-5))return false;
            }
        }
        return true;
    }
};