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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL || head->next==NULL || right==left)return head;

        ListNode* temp=head;
        ListNode* prev=NULL;
        int cnt=1;
        while(cnt<left){
            prev = temp;
            temp = temp->next;
            cnt++;
        }

        ListNode* leftNode=temp;
        ListNode* leftPrev=prev;
        prev=NULL;
        int steps = right-left+1;

        while(steps--){
            ListNode* front=temp->next;
            temp->next = prev;
            prev = temp;
            temp=front;
        }

        leftNode->next=temp;
        if(leftPrev)leftPrev->next=prev;
        else head=prev;

        return head;
    }
};