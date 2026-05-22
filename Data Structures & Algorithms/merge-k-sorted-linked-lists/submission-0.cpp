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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return NULL;
        
        int n = lists.size();
        while(n > 1){
            for(int i = 0; i < n/2; i++){
                lists[i] = mergeTwoLists(lists[i], lists[n-1-i]);
            }
            n = (n+1)/2;
        }
        return lists[0];
    }

     ListNode* mergeTwoLists(ListNode* t1, ListNode* t2) {
        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;

        while(t1 && t2){
            if(t1->val <= t2->val){
                temp->next = t1;
                t1=t1->next;
            }else{
                temp->next = t2;
                t2=t2->next;
            }
            temp=temp->next;
        }

        temp->next = t1?t1: t2;

        return dummy->next;
    }
};