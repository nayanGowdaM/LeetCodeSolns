class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tot = 0, mid=0, in=0;
        int n= cost.size();
        for( int i=0;i<n;i++){
            tot+= gas[i] - cost[i];
            mid+= gas[i] - cost[i];
            if(mid<0){
                mid=0;
                in = i+1;
            }
        }
        if( tot <0 ) return -1;
        return in;
        
    }
};