class Solution {
public:
    int minInsertions(string& a) {
        string b=a;
        reverse(b.begin(),b.end());
        int n=a.size();
        vector<int> prev(n+1,0),cur(n+1,0);
        // for(int i=0;i<=n;i++) prev[i]
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(a[i-1]==b[j-1]) cur[j]=1+prev[j-1];
                else cur[j] = max(cur[j-1],prev[j]);

            }
            prev=cur;
        }
        int ans=cur[n];
        return n-ans;
    }
};