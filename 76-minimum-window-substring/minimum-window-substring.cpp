class Solution {
    bool isValid( unordered_map<char,int>& s_mp, unordered_map<char,int>& t_mp, string& s){
        for(auto x: s){
            if(s_mp.find(x) == s_mp.end()   ||  s_mp[x] <t_mp[x]) return false;
        }
        return true;
    }
public:
    string minWindow(string s, string t) {
        if(s.size()< t.size()) return "";
        // string str="";
        int start=0, end=0,n=s.size(), ans=n+1,begin=-1;
        // unordered_map<char,int>s_mp, t_mp;
        int req=t.size();
        vector<int> rem( 128,0);
        for(auto x: t) rem[x]++;

        while( end< n){
            rem[s[end]]--;
            if( rem[s[end]]>=0) req--;
            while(req==0){
                if( ans > end-start+1){
                    ans = end-start+1;
                    begin=start;
                }
                rem[s[start]]++;
                if( rem[s[start]] > 0) req++;
                start++;
            }
            end++;
        }
        return begin==-1? "" : s.substr( begin, ans);

    }
};