class Solution {
    int greaterCount( vector<int>& arr, int val){
        auto it = upper_bound(arr.begin(), arr.end(), val);
        return arr.end()-it;
    }
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1,arr2,  arr11, arr22;
        int n=nums.size();
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        arr11.push_back(nums[0]);
        arr22.push_back(nums[1]);
        for( int i=2;i<n;i++){
            int x=greaterCount(arr1, nums[i]);
            int y=greaterCount(arr2, nums[i]);
            if(x>y){
                arr11.push_back(nums[i]);
                auto it = upper_bound(arr1.begin(), arr1.end(),nums[i]);
                arr1.insert(it, nums[i]);
                // cout<<"arr1"<<" ";
            }
            else if(x<y){
                arr22.push_back(nums[i]);
                auto it = upper_bound(arr2.begin(), arr2.end(),nums[i]);
                arr2.insert(it, nums[i]);
                // cout<<"arr2"<<" ";
            }
            else{
                if(arr1.size()<=arr2.size()) {
                    arr11.push_back(nums[i]);
                    auto it = upper_bound(arr1.begin(), arr1.end(),nums[i]);
                    arr1.insert(it, nums[i]);
                    // cout<<"arr1"<<" ";
                }
                else {
                    arr22.push_back(nums[i]);
                    auto it = upper_bound(arr2.begin(), arr2.end(),nums[i]);
                    arr2.insert(it, nums[i]);
                    // cout<<"arr2"<<" ";
                }
            }
        }
        for( int i=0;i<arr22.size();i++) arr11.push_back(arr22[i]);
        return arr11;
    }
};