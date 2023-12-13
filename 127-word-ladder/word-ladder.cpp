class Solution {
    bool find(string& s, string& t){
        int ct=0;
        for(int i=0;i<s.size();i++){
            if(s[i]!=t[i]) ct++;

        }
        return ct==1;
    }
    int bfs(string& s,  string& e,vector<string>& lst){
        // unordered_set<string> st;
        // st.insert(s);
        queue<pair<string, int>> q;
        q.push({s,0});
        while(!q.empty()){
            string str=q.front().first;
            int f=q.front().second;
            q.pop();
            // for(auto x:lst){
            //     if(st.find(x)==st.end()){
            //         if(find(x,str)){
            //             q.push({x,f+1});
            //             st.insert(x);
            //             if(x==e) return f+1;
            //         }
            //     }
            // }
            for(int i=0;i<lst.size();){
                if(find(lst[i],str)){
                    q.push({lst[i],f+1});
                    if(lst[i]==e) return f+1;
                    lst.erase(lst.begin()+i);
                    
                }
                else i++;
            }
        }
        return -1;
    }
public:
    int ladderLength(string s, string e, vector<string>& lst) {
        auto itr=::find(lst.begin(),lst.end(),e);
        if(itr==lst.end()) return 0;
        auto it=::find(lst.begin(),lst.end(),s);
        if(it!=lst.end()) lst.erase(it);
        int ans=bfs(s,e,lst);

        return ans+1;
    }
};