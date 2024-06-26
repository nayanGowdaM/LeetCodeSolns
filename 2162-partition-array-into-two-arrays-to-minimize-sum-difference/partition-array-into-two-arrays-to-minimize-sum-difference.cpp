class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n=nums.size(), N=n/2, res=0, sum=0;
        sum = accumulate( nums.begin(), nums.end(),0);
        vector<vector<int>> left(N+1), right(N+1);
        
        // haveing subset sum for left and right arrays 
        for(int mask=0;mask<( 1<<N);mask++){
            int sz=0, l=0, r=0;
            for(int i=0;i<N;i++){
                if( mask&(1<<i)){
                    sz++;
                    l+=nums[i];
                    r+=nums[N+i];
                }
            }
            left[sz].push_back(l);
            right[sz].push_back(r);
        }

        for( int i=0;i<=N;i++) sort( right[i].begin(), right[i].end());
        res = min( abs(sum-2*left[N][0]) , abs( sum - 2*right[N][0]));
        for( int sz=0 ; sz<=N;sz++){
            int rsz=N-sz;
            for( auto& a: left[sz]){
                int b = ( sum - 2*a)/2;
                auto& v = right[rsz];
                auto itr= lower_bound(v.begin(), v.end(), b);
                if(itr!=v.end()){
                    res = min( res,abs( sum - 2*(a+*itr)));
                }
                if( itr!=v.begin()){
                    auto it=itr;
                    it--;
                    res = min( res, abs( sum - 2*(a+*it)));
                }

            }
        }
        return res;
    }
};