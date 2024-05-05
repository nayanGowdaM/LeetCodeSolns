class Solution {
    bool valid( string s, int k){
        vector<int> hash( 26,0);
        int n=s.size();
        for(int i=0 ;i<k;i++) hash[s[i] - 'a']++;
        for(int i=k;i<n;i+=k){
            vector<int> hash2(26,0);
            for( int j=0;j<k;j++){
                hash2[s[i+j]-'a']++;
            }
            for( int j=0 ;j<26;j++) if( hash2[j] != hash[j]) return false;
        }
        return true;
    }
public:
    int minAnagramLength(string s) {

        int n=s.size();
        // int n=s.size();
        for( int i=1;i<=s.size();i++){
            if( n%(i) ==0 && valid(s, i)) return i;

        }
        return n;

    }
};