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

//官方解答
//没有用到vector
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        while (l1) {
            s1.push(l1 -> val);
            l1 = l1 -> next;
        }
        while (l2) {
            s2.push(l2 -> val);
            l2 = l2 -> next;
        }
        int carry = 0;
        ListNode* ans = nullptr;
        while (!s1.empty() or !s2.empty() or carry != 0) {
            int a = s1.empty() ? 0 : s1.top();
            int b = s2.empty() ? 0 : s2.top();
            if (!s1.empty()) s1.pop();
            if (!s2.empty()) s2.pop();
            int cur = a + b + carry;
            carry = cur / 10;
            cur %= 10;
			
			//这部分！！！
			//【特别巧妙】链表倒着保存了，按书写习惯保存，不需要再reverse，【画图便知】
            auto curnode = new ListNode(cur);
            curnode -> next = ans;
            ans = curnode;
        }
        return ans;
    }
};

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/add-two-numbers-ii/solution/liang-shu-xiang-jia-ii-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。