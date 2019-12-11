class Solution {
public:
    string simplifyPath(string path) {
        stack<string> res_path;
        string tmp,res;
        stringstream ss(path);
        while(getline(ss,tmp,'/')){
            if(tmp == "." || tmp == ""){
                continue;
            }else if(tmp == ".." ){
                if(!res_path.empty()){
                    res_path.pop();
                }
            }else{
                res_path.push(tmp);
            }
        }
        while(!res_path.empty()){
            if(res.size()!=0) {  
                res = res_path.top() + "/" + res;
            } else {
                res = res_path.top();
            }
            res_path.pop();
        }
        res = "/" + res;
        return res;
    }
};
