class Solution {
public:
    
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        k=n-k+1;
        priority_queue<int>pq;
        for(auto x: nums){
            pq.push(x);
            if(pq.size()>k) pq.pop();
        }
        return pq.top();
    }
};