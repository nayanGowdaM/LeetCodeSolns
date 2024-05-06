class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> s;
        unordered_set<int> prev;
        for( int i=0;i<arr.size();i++){
            unordered_set<int> cur;
            cur.insert( arr[i]);
            for( int x: prev) cur.insert( x | arr[i]);
            prev = cur;
            for( auto x: cur) s.insert( x);
        }
        return s.size();
    }
};