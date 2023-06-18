#include <bits/stdc++.h>
using namespace std;

const int N = 102;
const int M = 1e5 + 5;
int dp[N][M];
int nums[N];

int main() {
    int n, m;
    cin >> n >> m;
    for(int i=1; i<=n; i++)
        cin >> nums[i];

    dp[0][0] = 1;
    for(int i=1; i<=m; i++)
        dp[0][i] = 0;

    for(int i=1; i<=n; i++)
    {
        for(int target=1; target<=m; target++)
        {
            int ans1 = dp[i-1][target];
            if(target < nums[i]){
                dp[i][target] = ans1;
            }
            else{
                int ans2 = dp[i-1][target - nums[i]];
                dp[i][target] = ans1 or ans2;
            }
        }
    }
    cout << dp[n][m] << "\n";
    
    return 0;
}