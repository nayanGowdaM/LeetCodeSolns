class Solution {
public:
    int countStudents(vector<int>& stud, vector<int>& s) {
        int one =0,zero=0;

        for( int i=0;i<stud.size();i++) {
            if(stud[i]) one++;
            else zero++;
        }
        for( int i=0;i<s.size();i++){
            if(s[i] && one>0) one--;
            else if(s[i]== 0 && zero>0) zero--;
            else return max( one, zero);
        }
        return 0;
        
    }
};