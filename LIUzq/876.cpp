链表的中间节点
【本题中的含有头结点实际上是错误的】头结点怎么能有val呢，应该是null才对

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

//快慢指针：

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
        ListNode * p = head;
        ListNode * q = head;
        while(q != NULL && q->next != NULL){    //p != NULL不是这个，而是q，p肯定不会为空
            p = p->next;
            q = q->next->next;
        }
        return p;
    }
};