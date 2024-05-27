class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int ct1=0,ct2=0,el1=INT_MIN,el2=INT_MIN;
        int n = nums.size();
        for( auto x: nums){
            if( !ct1 && x!=el2){
                ct1=1;
                el1=x;
            }
            else if( !ct2 && x!=el1){
                ct2=1;
                el2=x;
            }
            else if( x==el1){
                ct1++;
            }
            else if( x==el2)ct2++;
            else{
                ct1--;
                ct2--;
            }
            
        }
        ct1=ct2=0;
        for( auto x: nums) if( x ==el1) ct1++; else if( x==el2) ct2++;
        vector<int> ans;
        if( ct1>n/3) ans.push_back( el1);
        if(ct2>n/3) ans.push_back(el2);
        return ans;
    }
};