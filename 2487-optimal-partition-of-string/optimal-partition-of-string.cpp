class Solution {
public:
    int partitionString(string s) {
        int i=0, n=s.size(), ans=0;
        while( i< n){
            unordered_set<char> st;
            while( i<n && st.find( s[i])==st.end()){
                st.insert( s[i]);
                i++;

            }
            ans++;
        }
        return ans;
    }
};