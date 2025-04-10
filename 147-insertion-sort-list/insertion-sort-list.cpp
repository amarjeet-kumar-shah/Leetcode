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
    ListNode* insertionSortList(ListNode* head) {
        if(head == NULL || head->next == NULL)
        {
            return head;
        }
        ListNode* h=head;
        head= head->next;
        h->next=NULL;
        while(head != NULL)
        {
            cout<<head->val;
            ListNode* t=h;
            ListNode *p=head->next;
            ListNode* prev=NULL;
            head->next= NULL;
            while(h->next != NULL && h->val<head->val)
            {
                prev=h;
                h=h->next;
            }
            if(h->next == NULL && h->val<head->val)
            {
                h->next=head;
            }
            else if(prev == NULL)
            {
                head->next=h;
                t=head;
            }
            else
            {
                head->next=prev->next;
                prev->next=head;
            }
            h=t;
            head=p;
        }
        return h;
    }
};