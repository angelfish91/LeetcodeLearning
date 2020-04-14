两数相加 II



//还可以，自己做出来了，注意数组到链表的拷贝，还有链表的创建等操作

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;

        //反转链表后相加，进位就将结果加一
        vector<int> ans;
        stack<int> ln1, ln2;
        while(l1 != nullptr){
            ln1.push(l1->val);
            l1 = l1->next;
        }
        while(l2 != nullptr){
            ln2.push(l2->val);
            l2 = l2->next;
        }
        int res = 0;
        while(!ln1.empty() || !ln2.empty() || res > 0){ //注意加入res的判断，比如 5 + 5 = 10
            //res += ln1.top() + ln2.top();
            res += ln1.empty() ? 0 : ln1.top();
            res += ln2.empty() ? 0 : ln2.top();
            if(!ln1.empty())   ln1.pop();
            if(!ln2.empty())   ln2.pop();
            if(res > 9){
                ans.emplace_back(res % 10);
                res = 1;
            }
            else{
                ans.emplace_back(res);
                res = 0;
            }
        }
        //这里可以继续用stack
        reverse(ans.begin(), ans.end());

        //数组数据拷贝到链表，注意具体方法  【for循环里面】
        ListNode *head, *node, *cur;
        head = node = new ListNode;
        node->val = ans[0];
        for(int i = 1; i < ans.size(); i++){
            cur = new ListNode;
            cur->val = ans[i];
            cur->next = nullptr;
            node->next = cur;
            node = cur;
        }
        return head;
    }
};