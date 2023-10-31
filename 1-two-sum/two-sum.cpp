class Solution {
public:
    vector<int> twoSum(vector<int>& a, int t) {
        map<int,int>mp;
        int n=a.size();
        for(int i=0;i<n;i++){
            int rem=t-a[i];
            if(mp.find(rem)!=mp.end()){
                return { i, mp[rem]};
            }
            mp[a[i]] = i;
        }
        return {-1,-1};
    }
};