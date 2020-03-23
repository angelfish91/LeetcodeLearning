链表的中间节点

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
    ListNode* middleNode(ListNode* head) {
        if(head->next == NULL) return head;
        ListNode *cur = head;
        int count = 0;
        while(cur != NULL){      //这里的问题，条件错误cur-> next != NULLx
            count ++;
            cur = cur->next;
        }
        cur = head;     //指针复位！！
        int mid = 0;    //
        while(mid < count / 2 && cur != NULL){       //count / 2 + 1是已经遍历到了这个节点，退出循环后就错过这个了
            mid ++;
            cur = cur->next;
        }
        return cur;
    }
};