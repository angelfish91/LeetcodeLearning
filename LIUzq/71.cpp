//最终提交版本
class Solution {
public:
    string simplifyPath(string path) {
        string temp;
        vector<string> vec;
        string res;
        for(int len = 0; len < path.size(); len ++){

            while(path[len] != '/' && len < path.size()){
                temp += path[len++];
            }
            if(temp == ".") {
                temp.clear();
                continue;
            }
            else if(temp ==".."){
                if(vec.empty()) {
                    temp.clear();
                    continue;
                }
                vec.pop_back();
                temp.clear();
                continue;
            }
            else if (temp.size() != 0){
                vec.push_back(temp);
                temp.clear();
            }
        } 
        for(int i=0; i<vec.size(); i++){
            res += '/';
            res.append(vec[i]);
        }
        if(res.size() == 0) res = "/";
        return res;
    }
};
//这个是错误的方法
class Solution {
public:
    string simplifyPath(string path) {
        string temp;
        vector<string> vec;
        string res;
        bool t = false;
        int count =0;
        for(auto ch : path){

            if(ch == '/' ) {
                count ++;
                t = true;
                continue;
            }
            else{
                t = false;
            }
            if(!t){
                temp += ch;
            }
            if(temp == ".") continue; //这里的temp是个缓存区，每次必须要清空。即每次continue之前都要清掉temp的值。！！！
            else if(temp == ".."){ //temp is a string ,so not '' ,is ""
                vec.pop_back();
                temp.clear();
            }
            else if(count >= 2 && temp.size() != 0){
                vec.push_back(temp);
                temp.clear();
                t = false;
                count = 0;
            }
        }
        for(int i=0; i<vec.size(); i++){
            res += '/';
            res.append(vec[i]);
        }
        if(res == " ") res == "/";
        return res;
    }
};

//参考答案
class Solution {
public:
    string simplifyPath(string path) {
        string result;
        vector<string> que;
        for(int i = 0; i < path.size(); i++)   //for(auto ch : path) 这种情况局限性较大，循环体内部不能进行小循环
        {
            string temp;  // 每次都会重新定义temp，即清空原来的值
            while(path[i] != '/' && i < path.size())
            {
                temp += path[i++];
            }
            if(temp == ".")
                continue;
            else if(temp == "..")
            {
                if(que.empty())
                    continue;
                que.pop_back();
                continue;
            }
            else if(temp.size() != 0)
                que.push_back(temp);
        }
        for(int i = 0; i < que.size(); i++)
        {
            result += '/';
            result.append(que[i]);
        }
        if(result.size()==0)return "/";
        return result;
    }
};