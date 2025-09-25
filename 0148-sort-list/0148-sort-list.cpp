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
    ListNode* merge(ListNode* left, ListNode* right){
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while(left && right){
            if(left->val <= right->val){
                tail->next = left;
                left = left->next;
            }else{
                tail->next = right;
                right = right->next;
            }
            tail = tail->next;
        }
        if(left){
            tail->next = left;
        }
        if(right){
            tail->next = right;
        }
        return dummy.next;
    }
    ListNode* splitmid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;
        while(fast != NULL && fast->next != NULL){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if(prev != NULL){
            prev->next = NULL;
        }
        return slow;
    }
    ListNode* mergesort(ListNode* head) {
        ListNode* slow;
        ListNode* fast;

        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* righthead = splitmid(head);

        ListNode* left = mergesort(head);
        ListNode* right = mergesort(righthead);

        return merge(left, right);
    }
    ListNode* sortList(ListNode* head) {
        return mergesort(head);
    }
};