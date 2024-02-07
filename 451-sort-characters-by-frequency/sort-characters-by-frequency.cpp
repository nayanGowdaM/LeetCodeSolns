class Solution {
public:
    string frequencySort(string s) {
        map<char, int> mp;
        priority_queue<pair<int,char>>pq;
        for( auto x: s){
            mp[x]++;
        }
        while(!mp.empty()){
            auto it = mp.begin();
            pq.push({it->second, it->first});
            mp.erase(it);
        }
        string ans="";
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int ct=it.first;
            while(ct--) ans+=it.second;
        }
        return ans;
    }
};