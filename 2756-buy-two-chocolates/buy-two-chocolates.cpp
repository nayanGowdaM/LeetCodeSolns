class Solution {
public:
    int buyChoco(vector<int>& a, int money) {
        priority_queue<int> pq;
        for(auto x: a){
            pq.push(x);
            if(pq.size()>2) pq.pop();
        }
        int ans=pq.top();
        cout<<pq.top();
        pq.pop();
        ans+=pq.top();
        cout<<pq.top();
        cout<<ans;
        return ans<=money? money-ans: money;
    }
};