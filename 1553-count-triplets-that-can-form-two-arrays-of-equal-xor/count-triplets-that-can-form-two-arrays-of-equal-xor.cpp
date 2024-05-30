class Solution {
public:
    int countTriplets(vector<int>& arr) {
        unordered_map<int,int> ctMap, totMap;
        vector<int> prefix;
        int ct=0;
        prefix.push_back( 0);
        for(int i=0;i<arr.size();i++){
             prefix.push_back( prefix[i]^arr[i]);
            //  cout<<prefix[i+1]<<" ";
        }
        for( int i=0;i<prefix.size();i++){
            ct+= ctMap[prefix[i]]++*(i-1) - totMap[prefix[i]];
            // ctMap[prefix[i]]++;
            totMap[prefix[i]] += i;
        }
        return ct;
    }
};