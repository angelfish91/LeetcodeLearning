class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> index;
        string tmp = s;
        string result = "";
        for(int i=0;i<s.size();i++){
            if(s[i] == '('){
                index.push(i);
            }
            else if(s[i] == ')'){
                index.push(i);
                int tail = index.top();
                index.pop();
                int header = index.top();
                index.pop();
                reverse(tmp.begin()+header,tmp.begin()+tail);
            }
      
        }
        for(int i = 0;i<tmp.size();i++){
            if(tmp[i]!= '(' && tmp[i]!=')')
                result.push_back(tmp[i]);
        }
        
        return result;
    }
};
