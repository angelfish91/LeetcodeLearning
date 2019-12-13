class Solution {
public:
    bool isValid(string s) {
        if(s.empty()) return true;
        if(s.length()%2 != 0) return false;
       stack<char> a ; //char  not int  注意栈的声明怎么用
       for (auto ch: s){
            switch(ch){
                case '(':
                case'[':
                case'{':
                    a.push(ch);
                    continue;
                case')':
                    if(a.empty()|| a.top() != '(') //栈顶元素必须与前一个对应，不然就invalid
                    //top是返回栈顶元素，不删除，pop是删除栈顶元素
                    return false;
                    a.pop();
                    continue;
                case']':
                    if(a.empty() || a.top()!= '[')
                    return false;
                    a.pop();
                    continue;
                case'}':
                    if(a.empty()|| a.top() != '{')
                    return false;
                    a.pop();
                    continue;
            }
       }
       return a.empty();
    }
};