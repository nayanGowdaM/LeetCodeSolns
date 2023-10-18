#include<bits/stdc++.h>
struct Node{
    int key,val,cnt;
    Node *next, *prev;
    Node(int _key,int _val){
        key=_key;
        val=_val;
        cnt=1;
    }
};

struct List{
    int size;
    Node* head;
    Node* tail;
    List(){
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
        size=0;
    }
    void addfront(Node *node){
        Node* temp=head->next;
        temp->prev=node;
        head->next=node;
        node->next=temp;
        node->prev=head;
        size++;
    }
    void removenode(Node *node){
        Node* delprev=node->prev;
        Node* delnext=node->next;
        delprev->next=delnext;
        delnext->prev=delprev;
        size--;
    }
};


class LFUCache {
public:
    map<int , Node*> keyNode;
    map<int , List*> freqListMap;
    int maxCacheSize, minFreq, curSize;
    LFUCache(int capacity) {
        curSize=0;
        minFreq=0;
        maxCacheSize=capacity;
    }

    void updateFreqListMap(Node *node){
        keyNode.erase(node->key);
        freqListMap[node->cnt]->removenode(node);
        if(node->cnt==minFreq && freqListMap[node->cnt]->size==0) minFreq+=1;
        node->cnt++;
        List *list=new List();
        if(freqListMap.find(node->cnt)!=freqListMap.end()) list=freqListMap[node->cnt];
        list->addfront(node);
        freqListMap[node->cnt]=list;
        keyNode[node->key]=node;
    }
    
    int get(int key) {
        if(keyNode.find(key)!=keyNode.end()){
            Node *temp=keyNode[key];
            int val=temp->val;
            updateFreqListMap(temp);
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(maxCacheSize==0) return ;
        if(keyNode.find(key)!=keyNode.end()){
            Node* node = keyNode[key];
            node->val=value;
            updateFreqListMap(node);
        }
        else{
            if(curSize==maxCacheSize){
                List *list=freqListMap[minFreq];
                Node* node=list->tail->prev;
                keyNode.erase(node->key);
                list->removenode(node);
                curSize--;
            }
            curSize++;
            Node* node=new Node(key,value);
            minFreq=1;
            List *list=new List();
            if(freqListMap.find(minFreq)!=freqListMap.end()){
                list=freqListMap[minFreq];
            }
            list->addfront(node);
            keyNode[key]=node;
            freqListMap[minFreq]=list;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */