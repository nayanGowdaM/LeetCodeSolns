class Solution {

    void  commonChars( vector<int>& mpa, string& b){
        vector<int>mpb(26,0);
        for( auto x: b) mpb[x-'a']++;
        for( int i=0;i<26;i++) mpa[i]=min( mpa[i], mpb[i]);
    }
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> ans;
        vector<int> mpa(26,0);
        int n=words.size();
        for( auto x: words[0]) mpa[x-'a']++;
        for(int i=0;i<n;i++) commonChars(mpa, words[i]);
        for( auto i=0;i<26;i++){
            while( mpa[i]){
                char temp = (i+'a');
                string t ;
                t.push_back( temp);
                ans.push_back(t );
                mpa[i]--;
            }
        }
        return ans;
    }
};