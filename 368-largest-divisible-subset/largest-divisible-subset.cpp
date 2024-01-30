class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<int> dp(n + 1, 1), hash(n + 1, 0);
        for (int i = 0; i < n; i++) {
            hash[i] = i;

            for (int j = 0; j < i; j++) {
                if (arr[i] % arr[j] == 0 && dp[i] < 1 + dp[j]) {
                    dp[i] = 1 + dp[j];
                    hash[i] = j;
                }
            }
        }
        int ans = -1;
        int lastidx = -1;
        for (int i = 0; i < n; i++) {
            if (dp[i] > ans) {
                lastidx = i;
                ans = dp[i];
            }
        }

        vector<int> res;
        while (hash[lastidx] != lastidx) {
            res.push_back(arr[lastidx]);
            lastidx = hash[lastidx];
        }
        res.push_back(arr[lastidx]);

        // reverse(res.begin(), res.end());
        return res;
    }
};