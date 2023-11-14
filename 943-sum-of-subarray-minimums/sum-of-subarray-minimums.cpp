class Solution {
public:
    int sumSubarrayMins(vector<int>& a) {
        int n=a.size(),M=1e9+7;
        stack<pair<int,int>>st;
        vector<int>nse(n),pse(n);
        st.push({INT_MIN,n});
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && a[i]<st.top().first) st.pop();
            nse[i]=st.top().second;
            if(a[i]==st.top().first)
            st.pop();
            st.push({a[i],i});
        }
        while(!st.empty()) st.pop();
        st.push({INT_MIN,-1});
        for(int  i=0;i<n;i++){
            while(!st.empty() && a[i]<=st.top().first) st.pop();
            pse[i]=st.top().second;
            st.push({a[i],i});
        }

        long long ans=0;
        for(int i=0;i<n;i++){
            long long ct=(abs(pse[i]-i)*1LL*abs(nse[i]-i))%M;
            long long to_add=(ct*a[i])%M;
            ans=(ans+to_add)%M;
        }
        return ans;
    }
};