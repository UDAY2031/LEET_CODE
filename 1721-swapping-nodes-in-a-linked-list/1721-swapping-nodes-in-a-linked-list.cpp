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
        int size = 0;

        while(head != NULL){
            head = head->next;
            size++;
        }
        return size;
    }
    ListNode* kthfromend(ListNode* head, int k){
        ListNode* right = head;
        int size = getsize(head);

        for(int i = 0; i < (size - k); i++){
            right = right->next;
        }
        return right;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* left = head;

        for(int i = 0; i < k - 1; i++){
            left = left->next;
        }

        ListNode* right = kthfromend(head, k);

        int temp = left->val;
        left->val = right->val;
        right->val = temp;
        return head;
    }
};