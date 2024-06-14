class Solution {
    const int M = 1e9 + 7;
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size(), ans=0;
        vector<int> left(n,-1), right(n,n);
        stack<int> st, stt;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()] > arr[i]) st.pop();
            if(st.empty()) left[i]=-1;
            else left[i]=st.top();

            st.push( i);
        }

        for( int i=n-1;i>=0;i--){
            while( !stt.empty() && arr[stt.top()]>=arr[i]) stt.pop();
            if(stt.empty()) right[i]=n;
            else right[i]=stt.top();
            stt.push( i);
        }
        for( int i=0;i<n;i++){
            int res =( (i-left[i])*1LL*(right[i]-i))%M;
            ans= (ans+0LL+res*1LL*arr[i])%M;
        }
        return ans;
    }
};