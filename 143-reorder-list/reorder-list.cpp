/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {

    ListNode* reverse( ListNode* root){
        if(!root || !root->next) return root;
        ListNode* prev=NULL, *cur=root, *next = root->next;
        while( cur){
            cur->next =  prev;
            prev=cur;
            cur=next;
            if( next ) next=next->next;
        }
        return prev;

    }
public:
    void reorderList(ListNode* head) {
        ListNode *slow= head, *fast=head;
        while( fast && fast->next){
            slow=slow->next;
            fast = fast->next->next;
        }
        ListNode* rev= reverse( slow);
        ListNode* cur1=head, *cur2 = rev, *next1=cur1->next, *next2=cur2->next;
        ListNode* check=rev;
        while( check) {
            cout<<check->val<<endl;
            check=check->next;
        }
        while( cur1 && cur2){
            next1=cur1->next;
            next2= cur2->next;
            // cout<<cur1->val<<" "<<cur2->val<<" "<<next1->val<<" "<<next2->val<<endl;
            cur1->next=cur2;
            cur2->next=next1;

            cur1=next1;
            cur2=next2;
        }

        if( cur1 &&cur1->next)  cur1->next->next=NULL;
    }
};