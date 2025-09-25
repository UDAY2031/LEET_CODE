/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int getsize(ListNode* head){
        int size = 0;

        while(head != NULL){
            head = head->next;
            size++;
        }
        return size;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int m = getsize(headA);
        int n = getsize(headB);
        ListNode* t1 = headA;
        ListNode* t2 = headB;
        int diff = 0;

        if(m >= n){
            diff = m - n;
            for(int i = 0; i < diff; i++){
                t1 = t1->next;
            }
        }else{
            diff = n - m;
            for(int i = 0; i < diff; i++){
                t2 = t2->next;
            }
        }
        while(t1 != NULL && t2 != NULL && t1 != t2){
            t1 = t1->next;
            t2 = t2->next;
        }
        if(t1 == NULL){
            return NULL;
        }else{
            return t1;
        }
    }
};