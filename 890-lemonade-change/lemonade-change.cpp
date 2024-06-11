class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0, ten=0;
        for( auto x: bills){
            // cout<<five<<" "<<ten<<endl;
            if( x== 5) five++;
            else if( x==10){
                if( five){
                    five--;
                    ten++;
                }
                else{
                    cout<<10<<" ";
                    return false;
                }
            }
            else{
                if( five && ten){
                    five--;
                    ten--;
                }
                else if( five>2)five-=3;
                else{
                    // cout<<20<<" ";
                    return false;
                }
            }
        }
        return true;
    }
};