#include<bits/stdc++.h>
using namespace std;

const int N = 100+5;
long long dp[N];

int main(){
    int n;
    cin >> n;

    dp[1] = 1;
    dp[2] = 1;

    for(int i=3; i<=n; i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }
    cout<<dp[n]<<"\n";

    return 0;
}