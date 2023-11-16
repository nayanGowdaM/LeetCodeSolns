class StockSpanner {
public:
    vector<int> v;
    stack<int> st;
    int i;
    StockSpanner() {
        i=0;
    }
    
    int next(int price) {
        v.push_back(price);
        while(!st.empty() && v[st.top()]<=price) st.pop();
        int res=st.empty()?-1:st.top();
        st.push(i);
        i++;
        return i-res-1;

    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */