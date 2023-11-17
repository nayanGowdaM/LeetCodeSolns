class LRUCache {
public:
    class node{
        public:
        int val,key;;;
        node* next;
        node* prev;
        node(int key_,int val_){
            val=val_;
            key=key_;
        }
    };
    node* head=new node(-1,-1);
    node* tail=new node(-1,-1);
    unordered_map<int,node*> mp;
    int cap;
    LRUCache(int capacity) {
        cap=capacity;
        tail->prev=head;
        head->next=tail;
    }

    void addnode(node* newnode){
        newnode->next=head->next;
        head->next->prev=newnode;
        newnode->prev=head;
        head->next=newnode;
    }
    void deletenode(node* delnode){
        node* delnext=delnode->next;
        node* delprev=delnode->prev;
        delprev->next=delnext;
        delnext->prev=delprev;
    }
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            node* res=mp[key];
            int ans=res->val;
            mp.erase(key);
            deletenode(res);
            addnode(res);
            mp[key]=head->next;
            return ans;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            node* delnode=mp[key];
            deletenode(delnode);
            mp.erase(key);
        }
        if(mp.size()==cap){
            mp.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new node(key,value));
        mp[head->next->key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */