class Solution {
public:
    string simplifyPath(string path) {
        vector<string> temp1;
        int len = path.length();
        int i = 0;
        while (i < len) {
            string t;
            bool tflag = false;
            while (i < len && path[i] == '/') {
                t = "/";
                tflag = true;
                i++;
            }
            if ((tflag&&temp1.size() == 0) || (tflag && t != temp1.back())) {
                temp1.push_back(t);
            }
            string mulu;
            while (i < len && path[i] != '/') {
                mulu += path[i];
                i++;
            }
            if (mulu == ".") {
                // ignore
            }
            else if (mulu == "..") {
                temp1.pop_back();
                if (temp1.size() > 0) {
                    temp1.pop_back();
                }
            }
            else {
                temp1.push_back(mulu);
            }
        }
        while (temp1.size() > 0 && (temp1[temp1.size() - 1] == "/"|| temp1[temp1.size() - 1] == "")) {
            temp1.pop_back();
        }
        string result;
        for (int index = 0;index < temp1.size();index++) {
            result += temp1[index];
        }
        return result.empty()?"/":result;
    }
};