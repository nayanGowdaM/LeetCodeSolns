class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        vector<int> ans;
        int i=0,j=0,n=nums.size();
        while(j<k-1){
             pq.push({nums[j],j});
             j++;
        }
        while(j<n){
            pq.push({nums[j],j});
            while(!pq.empty() &&pq.top().second<i){ pq.pop(); }
            ans.push_back(pq.top().first);
            j++;
            i++;
        }
        return ans;
    }
};