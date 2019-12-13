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
    bool isPalindrome(ListNode* head) {
        if(head == NULL)  return true;
        if(head -> next == NULL) return true;
        
        int i = 0;
        for(ListNode *l =head; l != NULL; l = l->next){
            i++;
        }
        //找到中间节点
        ListNode *p = head;
        for(int n=0; n< i/2; n++){
            p = p->next;
        }
        if(i%2 != 0) p = p->next;
        //p = p->next;
        ListNode* aa = reverseListNode(p);
        while(aa){
            if(aa->val != head->val){   //这里判断相等和不相等是有区别的，注意
                return false;   
            }
            aa = aa->next;
            head = head->next;
            
        }
        return true; //bug : forget to return
    }
    ListNode * reverseListNode(ListNode* pHead){
        if(pHead == NULL || pHead->next == NULL) return pHead;
        ListNode * a ,*b,*c;
        a = pHead;
        b = pHead->next;
        pHead->next = NULL;
        while(b){
            c = a->next;
            b->next = a;
            a = b;
            b = c;
        }
        pHead = a;
        return pHead;
    }
};