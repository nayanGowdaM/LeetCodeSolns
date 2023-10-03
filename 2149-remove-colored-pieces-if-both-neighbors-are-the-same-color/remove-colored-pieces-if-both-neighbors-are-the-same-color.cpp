class Solution {
public:
    bool winnerOfGame(string a) {
        int cta=0,ctb=0,i=0,n=a.size();
        while(i<n){
            int k=0;
            while((k+i)<n && a[k+i]=='A') k++;
            if(k>2) cta+=(k-2);
            if(k==0) k++;
            i=i+k;
        }
        i=0;
        while(i<n){
            int k=0;
            while((k+i)<n && a[k+i]=='B') k++;
            if(k>2) ctb+=(k-2);
            if(k==0) k++;
            i=i+k;
        }
        if(cta>ctb) return 1;
        else return 0;
    }
};