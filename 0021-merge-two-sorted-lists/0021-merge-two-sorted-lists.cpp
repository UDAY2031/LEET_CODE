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
    ListNode* merge(ListNode* list1, ListNode* list2){
        ListNode* i = list1;
        ListNode* j = list2;
        vector<int> ans;
        while(i != NULL && j != NULL){
            if(i->val <= j->val){
                ans.push_back(i->val);
                i = i->next;
            }else{
                ans.push_back(j->val);
                j = j->next;
            }
        }
        while(i != NULL){
            ans.push_back(i->val);
            i = i->next;
        }
        while(j != NULL){
            ans.push_back(j->val);
            j = j->next;
        }
        ListNode* head = NULL;
        ListNode* tail = NULL;
        for(int i : ans){
            ListNode* node = new ListNode(i);
            if(!head){
                head = tail = node;
            }else{
                tail->next = node;
                tail = node;
            }
        }
        return head;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        return merge(list1, list2);
    }
};