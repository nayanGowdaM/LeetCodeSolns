class Solution {
    unordered_map<int,unordered_map<int,int>> mp;
    int tryLock(int shift,int  keyIdx, string& ring, string& key, int minSteps){
        if( keyIdx ==key.size()) return 0;
        if( mp[shift][keyIdx]) return mp[shift][keyIdx];
        for(int i=0; i<ring.size();i++){
            if( ring[i] == key[keyIdx]){
                int totSteps = countSteps( shift, i, ring.size() ) + 1 + tryLock( i, keyIdx+1, ring, key, INT_MAX);
                minSteps = min( minSteps, totSteps);
            }
        }
        return mp[shift][keyIdx] = minSteps;
    }

    int countSteps( int shift, int idx, int ringSize){
        int stepsBetween = abs( idx - shift);
        int stepsAround = ringSize - stepsBetween;
        return min( stepsBetween, stepsAround);
    }
public:
    int findRotateSteps(string ring, string key) {
        return tryLock( 0,0,ring, key, INT_MAX);
    }
};