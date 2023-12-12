class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int,vector<int>, greater<int>>pq;
        pq.push(nums[0]);
        pq.push(nums[1]);
        for(int i=2;i<nums.size();i++){
            pq.push(nums[i]);
            while(pq.size()>2) pq.pop();
        }
        int x=pq.top();
        pq.pop();
        int y=pq.top();
        pq.pop();
        return (x-1)*(y-1);
    }
};