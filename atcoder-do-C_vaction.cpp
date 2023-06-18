#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int dp[N][4], happiness[N][4];

int solve(int day, int cur_task){
    if(day == 1){
        return happiness[day][cur_task];
    }

    if(dp[day][cur_task] != -1) return dp[day][cur_task];

    int mx_profit = 0;
    for(int last_ta = 1; last_ta <= 3; last_ta++){
        if(last_ta != cur_task){
            int cand_profit = solve(day-1, last_ta) + happiness[day][cur_task];
            mx_profit = max(cand_profit, mx_profit);
        }
    }

    dp[day][cur_task] = mx_profit;
    return dp[day][cur_task];
}

int main() {
    int n;
    cin >> n;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=3; j++)
            cin >> happiness[i][j];
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=3; j++)
            dp[i][j] = -1;
    }

    int a1 = solve(n, 1);
    int a2 = solve(n, 2);
    int a3 = solve(n, 3);

    cout << max({a1, a2, a3}) << "\n";

    return 0;
}