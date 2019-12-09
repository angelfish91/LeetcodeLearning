class Solution {
public:
    bool isValid(string s) {
        std::stack<char> br;
        for(int i=0;i<s.size();i++){
            char c = s[i];
            if( c == '(' || c=='[' || c == '{'){
                br.push(c);
            }
            else if(c==')'){
                if(br.empty() || br.top() != '(')
                    return false;
                br.pop();                
            }else if(c == ']'){
                if(br.empty() || br.top() != '[')
                    return false;
                br.pop();
            }else if(c == '}'){
                if(br.empty() || br.top() != '{')
                    return false;
                br.pop();
            }
        }
        return br.empty();
    } 
   
};
