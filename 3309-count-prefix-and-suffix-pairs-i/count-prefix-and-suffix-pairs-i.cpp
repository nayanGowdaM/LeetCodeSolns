class Solution {
    bool isPreSuf(string a, string b){
        if( a.size()> b.size()) return false;
        if( a == b.substr( 0, a.size()) && a==b.substr( b.size() - a.size(), a.size())) return true;
        return false;
    }
public:
    long long countPrefixSuffixPairs(vector<string>& words) {
        long long ans=0;
        for(int i=0;i<words.size();i++){
            for( int j=i+1;j<words.size();j++){
                if( isPreSuf( words[i], words[j])) ans++;
            }
        }
        return ans;
    }
};