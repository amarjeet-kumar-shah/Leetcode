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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *temp = head;
        ListNode *prev = NULL;
        while(temp!=NULL){
            if(temp->val==val){
                if(temp!=head){
                    prev->next = temp->next;
                    delete temp;
                    temp = prev->next;   
                }else{
                    head = head->next;
                    temp = head;
                }
            }else{
                prev = temp;
                temp = temp->next;
            }
        }
        return head;
    }
};