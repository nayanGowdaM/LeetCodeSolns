class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int ans=0;
        int n = grumpy.size();
        for( int i=0;i<n;i++) if( !grumpy[i]){
            ans+=customers[i];
            customers[i]=0;
        }

        int l=0, r=0;
        int res=0, window=0;
        while( r<n){
            window+= customers[r];
            if( r-l+1 == minutes){
                res=max( res, window);
                window-=customers[l];
                l++;
            }
            r++;
        }
        return res+ans;
    }
};