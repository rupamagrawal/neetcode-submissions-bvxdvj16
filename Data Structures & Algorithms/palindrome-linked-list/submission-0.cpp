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
public:
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next ==NULL)return true;

        ListNode* slow=head;
        ListNode* fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* newHead = reverseLL(slow->next);
        ListNode* first = head;
        ListNode* second = newHead;

        while(second){
            if(first->val != second->val){
                reverseLL(newHead);
                return false;
            }
            first = first->next;
            second = second->next;
        }
        reverseLL(newHead);
        return true;
    }

    ListNode* reverseLL(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr){
            ListNode* front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }
        return prev;
    }
};