class Solution {
public:
    int compareVersion(string v1, string v2) {
        stringstream s1( v1), s2(v2);
        string token1, token2;
        vector<int> tockens1, tockens2;
        char delimiter = '.';
        while( getline( s1, token1, delimiter)){
            tockens1.push_back(stoi(token1));
        }
        while( getline(s2,token2, delimiter )){
            tockens2.push_back(stoi(token2));
        }
        int i=0;
        for( ; i< min( tockens1.size(), tockens2.size()) ; i++){
            if( tockens1[i] < tockens2[i]) return -1;
            else if( tockens1[i]>tockens2[i]) return 1;
        }

        while( i< tockens1.size()){
            if(tockens1[i] > 0) return 1;
            i++;
        }
        while( i< tockens2.size()){
            if( tockens2[i] >0 ) return -1;
            i++;
        }
        return 0;
    }
};