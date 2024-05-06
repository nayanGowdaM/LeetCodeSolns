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
    ListNode* reverse( ListNode* head){
        ListNode* prev = NULL, *cur = head, *next=head->next;
        while( cur){
            cur->next=prev;
            prev = cur;
            cur=next ;
            if(next)
            next=next->next;
        }
        return prev;
    }
public:
    ListNode* removeNodes(ListNode* head) {
        ListNode *rev = reverse(head);
        ListNode *start = rev;
        while(rev->next){
            if(rev->next->val < rev->val) rev->next = rev->next->next;
            else rev = rev->next;
        }
        rev = reverse( start);
        return rev;
    }
};