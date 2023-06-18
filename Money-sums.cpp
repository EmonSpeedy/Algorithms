#include <bits/stdc++.h>

using namespace std;

const int N = 100;
const int SUM = 1e5;

bool dp[N + 1][SUM + 1];

int main() {
	int n;
	cin >> n;

	vector<int> values(n);
	for (int i = 0; i < n; i++){
        cin >> values[i];
    }

	dp[0][0] = true;

	for (int i = 1; i <= n; i++) {
		for (int crnt = 0; crnt <= SUM; crnt++) {
			dp[i][crnt] = dp[i - 1][crnt];
			int prv_sum = crnt - values[i - 1];
			if (prv_sum >= 0 && dp[i - 1][prv_sum]) {
				dp[i][crnt] = true;
			}
		}
	}

	vector<int> possible;
	for (int sum = 1; sum <= SUM; sum++) {
		if (dp[n][sum]){ 
            possible.push_back(sum); 
        }
	}

	cout << (int)(possible.size()) << endl;

	for (int sum : possible)
    { 
        cout << sum << " "; 
    }
	cout << "\n";
}