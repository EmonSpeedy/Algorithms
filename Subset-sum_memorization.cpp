#include <bits/stdc++.h>
using namespace std;

const int N = 102;
const int M = 1e5 + 5;
int dp[N][M];
int nums[N];

int subset_sum(int n, int target){
    if(n == 0){
        if(target == 0) return 1;
        return 0;
    }

    if(dp[n][target] != -1) return dp[n][target];

    int ans1 = subset_sum(n-1, target - nums[n]);
    int ans2 = subset_sum(n-1, target);
    if(nums[n] > target){
        dp[n][target] = ans2;
        return ans2;
    }
    int ans = ans1 or ans2;

    dp[n][target] = ans;
    return ans;
}

int main() {
    int n, target;
    cin >> n >> target;
    for(int i=1; i<=n; i++)
        cin >> nums[i];

    for(int i=0; i<=n; i++){
        for(int j=0; j<=target; j++){
            dp[i][j] = -1;
        }
    }

    cout << subset_sum(n, target) << "\n";

    return 0;
}