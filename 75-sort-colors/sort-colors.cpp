class Solution {
public:
    void sortColors(vector<int>& a) {
        int n=a.size(),low=0,mid=0,high=n;
        while(mid!=high){
            switch(a[mid]){
                case 0: swap(a[low],a[mid]);
                    mid++;
                    low++;
                    break;
                case 1: mid++;
                break;
                case 2: swap(a[mid],a[--high]);
                //high--;
                break;
            }
        }
    }
};

