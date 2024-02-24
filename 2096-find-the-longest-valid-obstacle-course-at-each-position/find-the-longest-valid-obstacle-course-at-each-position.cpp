class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obst) {
        vector<int> ans,temp;
        for( auto& x: obst){
            auto it=upper_bound(ans.begin(), ans.end() , x);
            temp.push_back(it-ans.begin() + 1);
            if( it==ans.end()) ans.push_back(x);
            else *it=x;
        }
        return temp;
    }
};