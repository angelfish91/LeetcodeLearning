#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> c(m, 0);
	vector<int> dp(n+1, 0);
	for (int i = 0; i < m; i++) {
		cin >> c[i];
	}
	for (int i = 0; i < m; i++) {
		dp[c[i]] ++;
	}
	sort(dp.begin(), dp.end());
    //这里不用sort会更好些，用ans记录最小的数
	cout << dp[1];
}