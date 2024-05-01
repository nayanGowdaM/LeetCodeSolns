class Solution {

    bool check( string& a, string& b, vector<int>& hash){
        for(int i=0;i<min( a.size(), b.size());i++){
            if(hash[a[i]-'a'] < hash[b[i]-'a']) return true;
            else if( hash[a[i]-'a'] > hash[b[i]-'a']) return false;
        }
        return a.size() <= b.size();
    }
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int>hash(26);
        for( int i=0;i<order.size();i++){
            hash[order[i]-'a'] = i;
        }
        for(int i=1;i<words.size();i++){
            if(!check(words[i-1], words[i], hash)) return false;
        }
        return true;
    }
};