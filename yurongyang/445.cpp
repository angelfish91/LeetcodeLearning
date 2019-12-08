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
        ListNode*  result = new ListNode(-1);
        if(l1 == NULL && l2 == NULL)
            return NULL;
        else if(l1 == NULL)
            return l2;
        else if(l2 == NULL)
            return l1;
        stack<int> s1;
        stack<int> s2;
        stack<int> re;
        while(l1 != NULL){
            s1.push(l1->val);
            l1 = l1->next;
        }
        while(l2 != NULL){
            s2.push(l2->val);
            l2 = l2->next;
        }
        int flag = 0;
        int sum = 0;
        while((!s1.empty()) && (!s2.empty())){
            sum = s1.top() + s2.top();
            int new_node = (sum + flag)%10;
            cout<<new_node<<endl;
            re.push(new_node);
            flag = (sum + flag)/10; 
            s1.pop();
            s2.pop(); 
        }
        while(!s1.empty()){
            re.push((s1.top()+flag)%10);
            flag = (s1.top()+flag)/10;
            cout<<flag<<endl;
            s1.pop();
        }
        while(!s2.empty()){
            re.push((s2.top()+flag)%10);
            flag = (s2.top()+flag)/10;
            cout<<flag<<endl;
            s2.pop();
        }
        if(flag == 1){
            re.push(1);
        }
        ListNode* pre=new ListNode(-1);
        result = pre;
        while(!re.empty()){
            ListNode* node = new ListNode(re.top());
            pre->next = node;
            pre = pre->next;
            re.pop();      
        }
        return result->next;
    }
};
