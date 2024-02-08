class Solution {
    int maxHisto(vector<int>& a){
        int n=a.size();
        if(n==1) return a[0];
        stack<int> st;
        int  ans = 0;
        for( int i=0;i<=n;i++){
            while(!st.empty() && ( i==n || a[st.top()]> a[i])){
                int height = a[st.top()];
                st.pop();
                int rightSmaller = i;
                int leftSmaller =-1;
                if(!st.empty()) leftSmaller = st.top();
                ans = max( ans, height * ( rightSmaller - leftSmaller -1 ));
            }
            st.push(i);
        }
        return ans;
    }
public:
    int maximalRectangle(vector<vector<char>>& arr) {
        int m=arr.size(), n=arr[0].size();
        vector<int> a(n,0);
        int ans=0;
        for( int i=0;i<m;i++){
            for( int j=0;j<n;j++){
                if(arr[i][j] =='0') a[j]=0;
                else a[j] += 1;
            }
            ans = max( ans, maxHisto(a));
        }
        return ans;
    }
};