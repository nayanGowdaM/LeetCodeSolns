class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        priority_queue<int>mx;
        priority_queue<int, vector<int> , greater<int>> mn;
        for(auto x: nums){
            mn.push(x);
            mx.push(x);
            while(mn.size()>2){
                mn.pop();
                mx.pop();
            }
        }
        int x=mx.top();
        mx.pop();
        int y=mx.top();
        mx.pop();
        int ans=x*y;
        x=mn.top();
        mn.pop();
        y=mn.top();
        mn.pop();
        ans-=x*y;
        return -ans;
    }
};