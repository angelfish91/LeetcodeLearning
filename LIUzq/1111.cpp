有效括号的嵌套深度

//【不会做，思路不对】
// 经验：
括号类题目 ：
			A：利用栈的思想进行遍历处理 + 模拟进行题目要求的行为
			B：碰到上述解决不了的或者设计组合，种类的题目就考虑dfs + 回溯
对半分	   ：
			A：与位运算挂钩			//奇数与1 & 操作，结果为1，偶数为0
			B：与奇偶性挂钩
			C：逻辑运算不错的话还能想到与异或挂钩
			
//栈的思想，但是栈里只有'(',没有必要去维护栈，只需要用一个变量模拟栈即可
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        //if(seq.empty())  return seq;
        vector<int> ans;
        int cnt = 0;
        int flag = 0;
        int mx = 0;
        for(auto ch : seq){
            if(ch == '('){
                cnt ++;
                ans.push_back(cnt);
                mx = max(mx, cnt);
            }
            else{
                ans.push_back(cnt);
                cnt --;
            }
        }
        flag = mx / 2;
        // for(auto ch : ans){      //只能遍历，不能修改值  
		//for (auto& e : dep) e = e > flag ? 1 : 0; // 加上& 就可以了！！
        //     ch = ch < flag ? 0 : 1;
        // }
        for(int i = 0; i < ans.size(); i++){
            ans[i] = ans[i] > flag ? 1 : 0;
        }
        return ans;
    }
};