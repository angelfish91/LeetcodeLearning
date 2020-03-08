//1103 分糖果II


class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> res(num_people, 0);
        int i = 0;
        while(candies > 0){         //不能是while（candies）  candies<0也是满足的！！
            res[i % num_people] += (candies - i - 1) > 0 ? i+1: candies;		//i % num_people很巧妙！
            candies -= (i + 1);
            i++;
        }
        return res;
    }
};