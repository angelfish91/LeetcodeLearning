class Solution {
public:
    int kthGrammar(int N, int K) {
        if(N == 1 && K == 1)
            return 0;
        int res = kthGrammar(N-1, (K+1)/2) == 1 ? K%2 : 1-K%2;
        return res;
    }
};