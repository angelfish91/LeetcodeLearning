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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> merge_vector;
        for(int i = 0;i<lists.size();i++) {
            ListNode* tmp = lists[i];
            while(tmp) {
                merge_vector.push_back(tmp->val);
                tmp = tmp->next;
            }
        }
        if(merge_vector.size() == 0) return NULL;
        sort(merge_vector.begin(),merge_vector.end());
        ListNode* merge = new ListNode(merge_vector[0]);
        ListNode* res = merge;
        for(int i = 1;i<merge_vector.size();i++) {
            ListNode* temp = new ListNode(merge_vector[i]);
            merge->next = temp;
            merge = merge->next;
        }
        return res;
    }
};