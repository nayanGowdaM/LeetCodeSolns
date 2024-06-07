struct Node{
    Node* links[26];
    bool flag = false;
    int idx=-1;

    bool containsKey( char ch){
        return links[ch-'a']!=NULL;
    }

    void put( char ch, Node* node, int i){
        links[ch-'a']=node;
        idx=i;
    }

    Node* get( char ch){
        return links[ch-'a'];
    }

    void setEnd(){
        flag=true;
    }

    bool isEnd(){
        return flag;
    }
};

class Trie{
    Node* root;
public:
    Trie(){
        root = new Node();
    }
    void insert( string word){
        Node* node = root;
        for( int i=0;i<word.size();i++){
            if( !node->containsKey( word[i])){
                node->put( word[i] , new Node(), i);
            }
            node = node->get( word[i]);
        }
        node->setEnd();
    }

    int searchRoot( string word){
        Node* node = root;

        for( int i=0;i<word.size();i++){
            if( node->containsKey( word[i])){
                node = node->get( word[i]);
                if( node->isEnd()){
                    return i;
                }
            }
            else return -1;
        }
        return -1;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dict, string s) {
        Trie* t = new Trie();
        string ans="";
        for( auto x: dict){
            t->insert( x);
        }
        int i=0,n=s.size();
        while( i<n){
            if( s[i]==' ') i++;
            else{
                int len=0;
                while( ( i+len)<n && s[i+len]!=' ') len++;
                string temp =  s.substr( i, len);
                int rootIdx=t->searchRoot(temp);
                if( rootIdx==-1){
                     ans+=temp;
                    //  cout<<temp<<endl;
                }
                else{
                     ans+=s.substr( i, rootIdx+1);
                    //  cout<<s.substr( i, rootIdx+1);
                }
                ans.push_back(' ');
                i+= len;
            }
        }
        ans.pop_back();
        return ans;
    }
};