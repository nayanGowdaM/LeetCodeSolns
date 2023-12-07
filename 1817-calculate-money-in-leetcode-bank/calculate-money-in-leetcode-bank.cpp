class Solution {
public:
    int totalMoney(int n) {
        int m=n/7,ans=0;
        ans+=28*m+m*(m-1)*7/2;
        int x=n%7;
        ans+=x*(x+1)/2+(x*(m));
        return ans;
    }
};