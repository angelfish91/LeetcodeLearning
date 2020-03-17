1160拼写单词


//用哈希表，但是和官方解法有所不同，这里用了count计数，运算比较复杂，还占多余的内存，
//实则只需要判断key的value是否大于等于chars里对应每个key的数目即可
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        
        int count = 0;
        int ans = 0;

        for(int i=0; i<words.size(); i++){
			//每次都重新申请一个map
            unordered_map<char,int> um;
            for(int i=0; i<chars.length(); i++){
                um[chars[i]] ++;               
            }
            for(int j=0; j<words[i].length(); j++){
                if(um.find(words[i][j]) != um.end()){
                    um[words[i][j]] --;
                    if(um[words[i][j]] >= 0){
                        count ++;
                    }  
                    else{
                        //小于0后说明不能拼出，跳出进行下一个判断
                        count = 0;
                        break;
                    }          
                }
                else{     
                    //这里的复位把前面的都否定了，另外用一个ans保存前面的答案               
                    count = 0;
                    break;
                }
                
            }
            ans += count;
            //保存完及时复位
            count = 0;
        }
        return ans;
    }
};


//另一种方法：判断长度
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char,int> charsCnt;
        bool isOwn = false;
        int ans = 0;
        for(char ch : chars){
            charsCnt[ch] ++;
        }
        for(string s : words){      //读取每个字符串
            unordered_map<char, int> wordsCnt;
            for(char ch : s){
                wordsCnt[ch] ++;
            }
            for(char ch : s){       //读取每个字符
                if(charsCnt[ch] >= wordsCnt[ch]){
                    isOwn = true;
                }else{
                    isOwn =false;
                    //一有不满足就跳出循环，进行下一轮判断
                    break;
                }              
            }
            if(isOwn){
                ans += s.length();
            }
        }
        return ans;
    }
};

//另一种方法：用一个长度为26的数组ch保存chars中每个字母出现的次数
//遍历words中的每个单词，同样用一个长度为26的数组wd保存单词中每个字母出现的次数，先在结果res中加上该单词的长度，
//再遍历数组，如果ch中的元素都大于等于wd中的元素，则表明该单词可以由chars构成。
//否则的话，在res中减去该单词的长度，跳出循环。

作者：jesse-42
链接：https://leetcode-cn.com/problems/find-words-that-can-be-formed-by-characters/solution/c-shu-zu-by-jesse-42/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

//该方法占内存较小，只用了数组而不是哈希表。
//【以后碰到只有小写或大写字母的可以用这种方法】
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int res=0;
        int ch[26]={0};
        for(char c:chars)
            ch[c-'a']++;
        
        for(string word:words)
        {
            int wd[26]={0};
            for(char c:word)
                wd[c-'a']++;
            res+=word.size();
            for(char c:word)
            {
                if(ch[c-'a']<wd[c-'a'])
                {
                    res-=word.size();
                    break;
                }    
            }
        }
        return res;
    }
};
