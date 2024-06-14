class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size(), ans=0;
        vector<int> left, right(n,0);
        int prev=0 ,next=0;
        for( int i=0;i<n;i++){
            left.push_back( prev);
            prev = max( prev, height[i]);
        }
        for( int i=n-1;i>=0;i--){
            right[i]=next;
            next = max( next, height[i]);
        }

        for( int i=0;i<n;i++){
            ans+= max( 0, min( left[i],right[i])-height[i]);
        }
        return ans;
    }
};