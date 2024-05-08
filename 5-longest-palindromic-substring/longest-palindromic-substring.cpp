class Solution {
    int x=-1,y=-1;

    bool solve(string& s, int i, int j){
        if( s[i]==s[j]){
            if( j-i <=2 ){
                if(y-x < j-i){

                    y=j;
                    x=i;
                }
                return true;
            }
            else{
                if( solve(s, i+1, j-1)){
                    if(y-x < j-i){

                        y=j;
                        x=i;
                    }
                    return true;
                }
                else return false;
            }
                

        }
        else{
            return solve( s, i+1, j) || solve(  s, i, j-1);
        }
    }
public:
    string longestPalindrome(string s) {
        int n = s.size(), x=-1,y=-1, len=0;
        vector<vector<int>>dp( n+1, vector<int>( n+1, 0));
        for( int i=n-1;i>=0;i--){
            for( int j=i;j<n;j++){
                if( s[i] == s[j]){
                    if( j-i <= 2) dp[i][j]=j-i+1;
                    else if( dp[i+1][j-1]){
                        dp[i][j] = dp[i+1][j-1] + 2 ;
                    }
                    else dp[i][j]=0;

                    if(len < dp[i][j]){
                        len = dp[i][j];
                        x = i;
                        y = j;
                    }
                }
                else dp[i][j] = 0;
            }
        }

        // for( int i=0;i<n;i++){
        //     for( int j=0;j<n;j++) cout<<dp[i][j] <<" ";
        //     cout<<endl;
        // }
        return s.substr( x, y-x+1);


    }
};