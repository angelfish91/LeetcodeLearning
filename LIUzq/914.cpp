//卡牌分组


//错误解答：思路不对
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        if(deck.empty() || deck.size() == 1) return false;
        //sort(deck.begin(), deck.end());
        unordered_map<int, int> um;
        for(int i=0; i<deck.size(); i++){
            um[deck[i]] ++;
        }
        int sum = 0;
        int minNum = 10001;
        bool isSuited = true;
        //sort(um.begin(), um.end());     //最小的数为X  不能用sort函数
        // for(int i=0; i<um.size(); i++){      //这里不能是i了，应该和deck挂钩
        //     sum += um[i];
        //     minNum = min(minNum, um[i]);
        // }
        for(int i=0; i<deck.size(); i++){
            sum += um[deck[i]];
            minNum = min(minNum, um[deck[i]]);
        }
        for(int i=0; i<deck.size(); i++){
            // if(um[deck[i]] % minNum == 0){      //如何做到有一个不满足就永久置为false，这里一旦最后一个满足就变为true了
            //     isSuited = true;
            // }
            // else{
            //     isSuited = false;
            // }
            if(um[deck[i]] % minNum != 0){      //虽然通过了[1,1,1,2,2,2,3,3]的测试，但是[1,1,1,1,2,2,2,2,2,2]不行，说明这个思路走不通，想想最大公约数！！行不行？
                isSuited = false;
            }
        }
        if(minNum > 1 && sum % minNum == 0 && isSuited) return true;        //考虑不周到，最后一个测试用例未通过
        //[1,1,1,2,2,2,3,3]
        return false;
    }
};


//最大公约数

class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        if(deck.empty() || deck.size() == 1) return false;
        unordered_map<int, int> um;
        for(int i=0; i<deck.size(); i++){
            um[deck[i]] ++;
        }
        int x = -1;
        for(int i=1; i<deck.size(); i++){
            //if(gcd(um[deck[i]], um[deck[i-1]]) > 1)  //不是两两求gcd而是前两个的gcd和下一个求gcd，一旦有1就为false；
            if(um[deck[i]] > 0){
                x = x == -1 ? um[deck[i]] : gcd(x, um[deck[i]]);
                if(x == 1)  return false;
            }
        }
        return x >= 2;
    }
private:
    int gcd(int a, int b){
        return (b == 0) ? a : gcd(b, a%b);
    }
};

//另一种解法：
class Solution {
    int cnt[10000];
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        //int cnt[10000];     //都是int的且大于0不需要用哈希表，数组即可
        //必须要申请为全局数组，下面一旦调用其他函数，这个值就不见了。
        for(int a : deck){
            cnt[a] ++;
        }
        int x = -1;
        for(int i=0; i<10000; i++){
            if(cnt[i]){     //一旦cn为0，就不会进入
                if(~x) x = gcd(x, cnt[i]);  //~是按位取反，和！是不一样的
                else   x = cnt[i];
            }
        }
        return x >= 2 ? true : false;
    }
private:
    int gcd(int a, int b){
        return b == 0 ? a : gcd(b, a%b);
    }
};