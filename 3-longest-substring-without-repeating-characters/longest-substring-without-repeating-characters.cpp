class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>st;
        int i=0,j=0,n=s.size(),m=0;
        while(j<n && i<=j){
            if(st.find(s[j])!=st.end()){
                while(st.find(s[j])!=st.end()){
                    st.erase(st.find(s[i]));
                    i++;
                }
            }
            m=max(m,j-i+1);
            st.insert(s[j]);
            j++;

            }

        return m;
        }
    };
