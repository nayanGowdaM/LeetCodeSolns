class Solution {
public:
    int buyChoco(vector<int>& a, int money) {
        int idx=min_element(a.begin(),a.end())-a.begin();
        int m=INT_MAX;
        for(int i=0;i<a.size();i++){
            if(idx!=i){
                m=min(m,a[i]);
            }
        }
        int ans=a[idx]+m;
        cout<<a[idx]<<" "<<m;
        if(ans<=money) return money-ans;
        else return money;
    }
};