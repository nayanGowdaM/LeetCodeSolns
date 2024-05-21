class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        for( int i=k;i<n;i++){
            if( energy[i-k]>0)
            energy[i] += energy[i-k];
        }
        int ans = *max_element(energy.end()-k,energy.end());
        return ans;
    }
};