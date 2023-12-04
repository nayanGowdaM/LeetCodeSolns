class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> mp;
        int ans=0;
        for(auto x: chars) mp[x]++;
        for(auto x: words){
            unordered_map<char, int> hash;
            bool flag=true;
            for(auto y: x){
                if(mp.find(y)==mp.end()|| mp[y]<=hash[y]) {
                    flag = false;
                    break;
                }
                else{
                    hash[y]++;
                }
            }
            if(flag) ans+=x.size();
        }
        return ans;
    }
};