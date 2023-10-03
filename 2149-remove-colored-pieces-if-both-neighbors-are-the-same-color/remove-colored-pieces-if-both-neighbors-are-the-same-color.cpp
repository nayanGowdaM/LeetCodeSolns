class Solution {
public:
    bool winnerOfGame(string a) {
        int ca=0,cb=0,n=a.size();
        for(int i=1;i<n-1;i++){
            if(a[i]==a[i-1] && a[i]==a[i+1]){
                if(a[i]=='A') ca++;
                else cb++;
            }
        }
        return ca>cb;
    }
};