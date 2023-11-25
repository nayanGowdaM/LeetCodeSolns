class MedianFinder {
public:
    MedianFinder() {
        
    }
    priority_queue<int>maxH;
    priority_queue<int,vector<int>,greater<int>>minH;
    
    void addNum(int num) {
        int l=maxH.size(),r=minH.size();
        if(l==0)maxH.push(num);
        else{
            if(l==r){
                if(num<minH.top()) maxH.push(num);
                else{
                    int temp=minH.top();
                    minH.pop();
                    minH.push(num);
                    maxH.push(temp);
                }
            }
            else{
                if(num>=maxH.top()){
                    minH.push(num);
                }
                else{
                    int temp=maxH.top();
                    maxH.pop();
                    minH.push(temp);
                    maxH.push(num);
                }
            }
        }
        if(!maxH.empty() && !minH.empty())cout<<maxH.top()<<" "<<minH.top()<<endl;

    }
    
    double findMedian() {
       if(minH.size()==maxH.size()) return ((double)maxH.top()+minH.top())/2;
       return maxH.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */