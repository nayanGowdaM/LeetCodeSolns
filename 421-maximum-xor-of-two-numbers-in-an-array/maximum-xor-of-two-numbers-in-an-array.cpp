struct Node{
    Node* links[2];

    bool containsBit(int bit){
        return links[bit]!=NULL;
    }

    void put( int bit, Node* node){
        links[bit] = node;
    }

    Node* get( int bit){
        return links[bit];
    }
};


class Trie{
    Node* root;
public:
    Trie(){
        root=new Node();
    }

    void insert( int num){
        Node* node = root;
        for( int i=31;i>=0;i--){
            int bit = (num>>i) & 1;
            if(! node->containsBit( bit)){
                node->put( bit, new Node());
            }
            node=node->get( bit);
        }
    }


    int maxXor( int num){
        int maxi = 0;
        Node* node = root;
        for( int i=31;i>=0;i--){
            int bit = (num>>i) & 1 ;
            if( node->containsBit( 1-bit)){
                maxi = maxi | (1<<i);
                node = node->get( 1-bit);
            }
            else{
                node = node->get( bit);
            }
        }
        return maxi;
    }
};



class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie* t = new Trie();

        for( auto x : nums) t->insert( x);
        int ans = 0;
        for( auto x: nums) ans = max( ans, t->maxXor( x));
        return ans;
    }
};