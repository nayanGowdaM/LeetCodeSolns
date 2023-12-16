class Solution {
public:
    bool isAnagram(string s, string t) {
        int m=s.size(),n=t.size();
        if(m!=n)return false;
        vector<int> v(26,0);
        for(auto x: s) v[x-'a']++;
        for(auto x: v) cout<<x<<" ";
        for(auto x: t) v[x-'a']--;
        cout<<endl;
        for(auto x : v) cout<<x<<" ";
        for(auto x: v) if(x)return false;
        return true;
    }
};