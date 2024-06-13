class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort( seats.begin(), seats.end());
        int ans=0;
        sort( students.begin(), students.end());
        for( int i=0;i<seats.size();i++){
            ans+= abs( seats[i] - students[i]);
        }
        return ans;
        
    }
};