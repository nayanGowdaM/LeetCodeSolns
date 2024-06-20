class Solution {
    bool possible( vector<int>& pos, int  m, int len){
        auto left = pos.begin() , right = pos.end();
        int ct=m-1;
        auto it = pos.begin();
        // cout<< len<<" ";
        while( ct ){
            auto x = lower_bound( left, right, *it + len);
            if( x==pos.end()) return false;
            // cout<<*x<<" ";
            left = x;
            ct--;
            it=x;
        }
        return true;
    }
public:
    int maxDistance(vector<int>& pos, int m) {
        sort( pos.begin(), pos.end());
        int l = 0, r=*max_element( pos.begin() ,pos.end());

        while( l<=r){
            int mid =  l+ ( r-l)/2;
            bool poss = possible( pos, m, mid);
            if( !poss){
                // cout<<"false"<<endl;
                 r = mid-1;
            }
            else{
                // cout<<"true"<<endl;
                 l = mid+1;
            }
        }
        return l-1;
    }
};