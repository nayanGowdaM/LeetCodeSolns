class Solution {
int bfs( vector<string>& a, string tar){
    vector<bool>vis(10002, false);
    for( auto x: a){
        vis[stoi( x)] = true;
    }
    if(vis[0]) return -1;
    queue<pair<int,string>>q;
    q.push({0,"0000"});
    while(!q.empty()){
        int len=q.front().first;
        string node = q.front().second;
        q.pop();
        if(node == tar) return len;
        for( int i=0;i<4;i++){
            int add = ((node[i] - '0') +1 )%10, sub = ((node[i]-'0')-1)%10;
            if(sub<0) sub+=10;
            string child1=node, child2=node;
            child1[i]=add+'0';
            child2[i] = sub+'0';
            // cout<<child1<<" "<<child2<<endl;
            // cout<<stoi(child1)<<" "<<stoi(child2)<<endl;
            if(!vis[stoi(child1)]){
                vis[stoi(child1)] = true;
                q.push({len+1,child1});
            }
            if(!vis[stoi(child2)]){
                vis[stoi(child2)] = true;
                q.push({len+1,child2});
            }

        }
    }
    return -1;
}
public:
    int openLock(vector<string>& deadends, string target) {
        return bfs(deadends, target);
    }
};