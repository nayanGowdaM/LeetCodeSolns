class Solution {

public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //Row 
        for( int i=0;i<9;i++){
            unordered_set<char> st;
            for( int j=0 ;j<9 ;j++){
                if( st.find( board[i][j])!=st.end()) return false;
                if( board[i][j] !='.')st.insert( board[i][j]);
            }
        }
        // cout<<"ROw"<<endl;

        //col
        for( int j=0;j<9;j++){
            unordered_set<char> st;
            for( int i=0 ;i<9 ;i++){
                if( st.find( board[i][j])!=st.end()) return false;
                if( board[i][j] !='.')st.insert( board[i][j]);
            }
        }
        // cout<<"Col"<<endl;
        for(int box = 0;box<9 ;box++){
            int x=box/3,y=box%3;
            x=x*3;
            y=y*3;
            unordered_set<char> st;
            for( int i=0;i<3;i++){
                for( int j=0;j<3;j++){
                    // cout<<i+x<<" "<<j+y<<endl;
                    if( st.find( board[i+x][j+y])!=st.end()) return false;
                    if( board[i+x][j+y] !='.')st.insert( board[i+x][j+y]);   
                }
            }
            // cout<<"BOx "<<box<<endl;
        }
        // cout<<"Box";
        return true;
    }
};