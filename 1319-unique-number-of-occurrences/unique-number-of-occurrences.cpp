class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_set<int> st;
        sort(arr.begin(),arr.end());
        int i=0,n=arr.size();
        while(i<n){
            int ct=1;
            while(i<n-1 && arr[i]==arr[i+1]) {ct++;i++;}
            if(st.find(ct)!=st.end()) return false;
            st.insert(ct);
            i++;
        }
        return true;
    }
};