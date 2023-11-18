class Solution {
public:
    
    bool is_valid(string& s,vector<int>& hash , int i, int j, int k){
        int n=s.size(),mx=*max_element(hash.begin(),hash.end());
        return (j-i+1-mx)<=k?true:false;
    }
    int characterReplacement(string s, int k) {
        vector<int> hash(26,0);
        int n=s.size(),ans=0;
        for(int i=0,j=0;j<n;){
            // hash[s[j]-'A']++;
            // if(is_valid(s,i,j,k)){
            //     ans=max(ans,j-i+1);
            //     j++;
            // }
            // else{
            //     while(!is_valid(s,i,j,k)){
            //         hash[s[i]]--;
            //         i++;
            //     }
            // }
            hash[s[j]-'A']++;
            while(!is_valid(s,hash,i,j,k)){
                hash[s[i]-'A']--;
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};