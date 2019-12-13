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
        if(head == NULL || head -> next == NULL)  return true;
        //求链表长度        
        int i = 0;
        for(ListNode *l =head; l != NULL; l = l->next){
            i++;
        }
        //找到中间节点
        ListNode *p = head;
        for(int n=0; n< i/2; n++){
            p = p->next;
        }
        if(i%2 != 0){
            p = p->next;
        } 
        ListNode* node = p;
        ListNode* rhead = NULL;
        while(node){
            ListNode* next = node->next;
            node->next = rhead;
            rhead = node;
            node = next;
        }
        ListNode* p2 = rhead;
        ListNode* p1 = head;
        while(p2){
            if(p2->val != p1->val){   //这里判断相等和不相等是有区别的，注意
                return false;   
            }
            p2 = p2->next;
            p1 = p1->next;
            
        }
        return true; //bug : forget to return
    }
};