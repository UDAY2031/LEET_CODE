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
    int getsize(ListNode* head){
        ListNode* temp = head;
        int s = 0;
        while(temp != NULL){
            temp = temp->next;
            s++;
        }
        return s;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = getsize(head);
        ListNode* prev = head;
        if(n == size){
            return head->next;
        }
        for(int i = 1; i < (size - n) ; i++){
            prev = prev->next;
        }
        prev->next = prev->next->next;
        return head;
    }
};