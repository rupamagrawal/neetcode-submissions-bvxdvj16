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
    void reorderList(ListNode* head) {
         if(!head || !head->next) return;
        
        ListNode* slow =head;
        ListNode* fast = head->next;
        
        // Find the Middle of LL
        while(fast && fast->next){
            slow =  slow->next;
            fast = fast->next->next;
        }

        //Make 2 LL and reverse 2nd LL
        ListNode* first = head;
        ListNode* second = ReverseLL(slow->next);
        slow->next=NULL;

        //Merge both LL by taking one from each
        while(second){
            ListNode* temp1 = first->next;
            first->next = second;
            ListNode* temp2 = second->next;
            second->next = temp1;
            first = temp1;
            second = temp2;
        }
    }

    ListNode* ReverseLL(ListNode* head){
        ListNode* curr=head;
        ListNode* prev = NULL;
        ListNode* front = NULL;

        while(curr){
            front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }
        return prev;

    }
};
