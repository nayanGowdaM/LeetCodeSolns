class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        long long ans=0;
        vector<int> lm(n,-1),lmx(n,-1),rm(n,n),rmx(n,n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]>=nums[i] )st.pop();
            if(!st.empty())lm[i]=st.top();
            st.push(i);
        
        }
        while(!st.empty()) st.pop();
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]<=nums[i] )st.pop();
            if(!st.empty())lmx[i]=st.top();
            st.push(i);
        
        }
        while(!st.empty()) st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]>nums[i] )st.pop();
            if(!st.empty())rm[i]=st.top();
            st.push(i);
        
        }
        while(!st.empty()) st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]<nums[i] )st.pop();
            if(!st.empty())rmx[i]=st.top();
            st.push(i);
        
        }
        for(auto x: lm) cout<<x<<" ";
        cout<<endl;
        for(auto x: lmx) cout<<x<<" ";
        cout<<endl;
        for(auto x: rm) cout<<x<<" ";
        cout<<endl;
        for(auto x: rmx) cout<<x<<" ";
        cout<<endl;
        for(int i=0;i<n;i++){
            long long m=(i-lm[i])*(rm[i]-i);
            long long mx=(i-lmx[i])*(rmx[i]-i);
            ans+=(mx-m)*nums[i];
        }
        return ans;
    }
};