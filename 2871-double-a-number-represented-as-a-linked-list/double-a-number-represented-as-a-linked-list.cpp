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

    ListNode* rev( ListNode* head){
        ListNode* next = NULL, *prev=NULL, *cur = head;
        while( cur){
            next = cur->next;
            cur->next = prev;
            prev=cur;
            cur=next;
        } 
        return prev;
    }
public:
    ListNode* doubleIt(ListNode* head) {
        ListNode* r = rev( head), *cur=r;
        int carry =0;
        while( cur ){
            int temp = 2*cur->val + carry;
            carry = temp/10;
            cur->val = temp%10;
            cur = cur->next;
        }
        if( carry){
            ListNode* ans = new ListNode(1);
            ans->next = rev( r);
            return ans;
        }
        return rev(r);
    }
};