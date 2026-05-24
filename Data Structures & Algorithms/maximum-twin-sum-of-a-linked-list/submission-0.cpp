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
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast && fast->next){
            slow = slow -> next;
            fast = fast->next->next;
        }
        ListNode* first = head;
        ListNode* second = reverseLL(slow->next);
        slow->next = NULL;

        int maxSum = INT_MIN;
        while(second){
            maxSum = max(maxSum, first->val + second->val);
            first = first->next;
            second = second->next;
        }
        return maxSum;
    }

    ListNode* reverseLL(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = NULL;

        while(curr){
            ListNode* front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }
        return prev;
    }
};