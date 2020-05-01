21合并两个有序链表

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        //任一个为null就返回另一个
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
                    //以l1为站好的队列，不能不用新的指针只用l1和l2来进行插入和移动操作，会混乱
                    // while(l1 != NULL || l2 != NULL){
                    //     if(l2->val > l1->val){

                    //     }
                    //     else{
                    //         l2->next = l1->next;
                    //         l1->next = l2;
                    //         l1 = l1->next;
                    //         l2 = l
                    //     }
                    // }
        //这种要用delete，否则会内存泄漏
        //ListNode* p = new ListNode(0);
        //这种直接在栈上分配，避免内存泄漏问题
        ListNode newHead(0);
        ListNode* p = &newHead;
		//这部分可以按照评论区里大佬的解法，用swap，省去一个else语句，见下一个解答
		
        while(l1 != NULL && l2 != NULL){
            if(l2->val > l1->val){
                p->next = l1;
                p = p->next;
                l1 = l1->next;
            }else{
                p->next = l2;
                p = p->next;
                l2 = l2->next;
            }
        }
        if(l1 == NULL) p->next = l2;
        if(l2 == NULL) p->next = l1;
        //这样只能返回p现在指向的位置及后面的元素，例如[1->2->4]和[1->3->4]返回[4,4]
        //return p;
        return newHead.next;
    }
};

//评论区大佬解答
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode newHead(0);
        ListNode *pi = &newHead;
        while(l1 && l2) {
            if(l1->val > l2->val) swap(l1, l2);	//始终保持l1为最小的那个，swap函数的新用法
            pi->next = l1;
            l1 = l1->next;
            pi = pi->next;
        }
        pi->next = l1 ? l1 : l2;
        return newHead.next;
    }
};

//另外的解答，学习一下

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* res=new ListNode;//整一个头节点		【这里】
        ListNode* p=res;
        while(l1!=NULL&&l2!=NULL){
            if(l1->val<l2->val)p->next=l1,l1=l1->next;
            else p->next=l2,l2=l2->next;
            p=p->next;//【这里】不用写重复的
        }
        if(l1==NULL)p->next=l2;
        else if(l2==NULL)p->next=l1;
        return res->next;
    }
};

//官方递归解法
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        if(l1->val <= l2->val){
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else{
            l2->next = mergeTwoLists(l2->next, l1);
			//这一句也可以，l2->next 的位置在前在后都可以！！
			//l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};