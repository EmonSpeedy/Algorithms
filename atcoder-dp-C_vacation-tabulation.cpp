#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int dp[N][4], happiness[N][4];

int main() {
    int n;
    cin >> n;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=3; j++)
            cin >> happiness[i][j];
    }

    for(int i=1; i<=3; i++)
        dp[1][i] = happiness[1][i];

    for(int day=1; day<=n; day++) 
    {
        for(int cur_task=1; cur_task<=3; cur_task++)
        {
            int mx_profit = 0;
            for(int last_task = 1; last_task <= 3; last_task++)
            {
                if(cur_task != last_task){
                    int cand_profit = dp[day-1][last_task] + happiness[day][cur_task];
                    mx_profit = max(cand_profit, mx_profit);
                }
            }
            dp[day][cur_task] = mx_profit;
        }
    }
    cout<< max({dp[n][1], dp[n][2], dp[n][3]}) << "\n";

    return 0;
}