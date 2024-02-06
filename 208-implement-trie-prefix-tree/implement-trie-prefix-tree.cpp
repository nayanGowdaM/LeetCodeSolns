
struct Node {
    Node* links[26];
    bool flag =  false ;

    bool hasKey( char key){
        return links[key-'a'] != NULL;
    }
    void put( char key, Node* node){
        links[key-'a'] = node;
    }
    void SetEnd(){
        flag = true;
    }
    Node* getKey( char key){
        return links[key-'a'];
    }

    bool isEnd( ){
        return flag;
    }

};



class Trie {
     Node* root;
public:
    Trie() {
       root = new Node();
    }
    
    void insert(string word) {
        Node* node = root ;
        for( int i=0;i<word.size();i++){
             if(! node->hasKey(word[i])){
                 node->put( word[i], new Node());
             }
            node = node->links[word[i]-'a'];
        }
        node->SetEnd();
    }
    
    bool search(string word) {
        Node* node = root;
        for( int i=0;i<word.size();i++){
            if( !node->hasKey( word[i])) return false;
            node = node->getKey(word[i]);
        }
        return node->isEnd();

    }
    
    bool startsWith(string word) {
        Node* node = root;
        for( int i=0;i<word.size();i++){
            if( ! node->hasKey(word[i])) return false;
            node =  node->getKey(word[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */