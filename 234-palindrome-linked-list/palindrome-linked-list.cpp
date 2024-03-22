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
    ListNode* rev(ListNode* t){
        ListNode* prev=NULL, *cur=t, *next;
        if(!t || !t->next) return t;
        next=t->next;
        while(cur){
            cur->next=prev;
            prev=cur;
            cur=next;
            if(next) next=next->next;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        ListNode* fast= head, *slow=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        if(fast) slow=slow->next;
        ListNode* temp=rev( slow);
        while(head && temp){
            if(head->val != temp->val) return false ;
            head=head->next;
            temp=temp->next;
        }
        return true;
    }
};