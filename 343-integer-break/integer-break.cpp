class Solution {
public:
    int find(int n, int k){
        int ans=n/k,rem=n%k,res=1;
        k=k-rem;
        while(rem--) res*=(ans+1);
        while(k--) res*=ans;
        return res;
    }
    int integerBreak(int n) {
        if(n<3) return 1;
        int l=2,r=n,al=find(n,l),ar=find(n,r);
        cout<<al;
        while((r-l)>1){
            int m=(l+r)/2;
            int am=find(n,m);
            if(ar==al){
                l++;
                r--;
                al=find(n,l);
                ar=find(n,r);
            }
            if(al<ar) {
                al=am;
                l=m;
            }
            else{
                ar=am;
                r=m;
            }
        }
        return al>ar?al:ar;
    }
};