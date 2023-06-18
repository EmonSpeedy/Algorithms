#include <bits/stdc++.h>
using namespace std;

const int N = 102;
const int M = 1e5 + 5;
long long dp[N][M];
int wt[N], val[N];

int main() {
    int n, w;
    cin >> n >> w;

    for(int i=1; i<=n; i++){
        cin >> wt[i] >> val[i];
    }

    for(int i=0; i<=w; i++)
        dp[0][i] = 0;

    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<=w; j++)
        {
            if(j < wt[i]){
                dp[i][j] = dp[i-1][j];
                continue;
            }
            dp[i][j] = max(val[i] + dp[i-1][j - wt[i]], dp[i-1][j]);
        }
    }
    cout << dp[n][w] << "\n";

    return 0;
}