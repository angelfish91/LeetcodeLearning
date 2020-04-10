翻转字符串里的单词

//自己想到的方法，bug较多，最后accept
看到字符串要考虑为空和空格的情况
//利用stack
class Solution {
public:
    string reverseWords(string s) {
        if(s.empty())   return s;
        
        stack<string> stk;
        string s1, ans;
        for(char ch : s){
            
            if(ch != ' '){
                s1 += ch;
            }
            else if(!s1.empty() && ch == ' '){
                stk.push(s1);
                s1.clear();
            }
        }
        //ch到‘\0’时，最后一个s1没放进去 the sky is blue
        if(!s1.empty()) stk.push(s1);   //如果最后有空格，s1无值，但是push的话就加成了空格
        while(!stk.empty()){    //最后是没有空格的
            ans += stk.top();
            stk.pop();
            ans += ' ';
        } 
        if(!ans.empty())    //如果输入都为空格，ans为空
            ans.pop_back();     //去掉最后加上的空格
        return ans;
    }
};

官方题解里有其他方法，包括双端队列deque，字符串去除多余空格后整个反转，见官方题解
