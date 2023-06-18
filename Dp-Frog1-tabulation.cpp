#include<bits/stdc++.h>

using namespace std;

//Tabulation method
const int N = 1e6;
int h[N];
int dp[N];

int main(){
    int n;
    cin >> n;

    for(int k=1; k<=n; k++)
        dp[k] = -1;

    for(int i=1; i<=n; i++)
        cin>>h[i];
   
    dp[1] = 0;
    for(int i=2; i<=n; i++)
    {
        int a1, a2;
        a1 = dp[i-1] + abs(h[i] - h[i-1]);
        a2 = dp[i-2] + abs(h[i] - h[i-2]);
        if(i == 2){
            dp[i] = a1;
        }
        int can_ans = min(a1, a2);

        dp[i] = can_ans;
    }
    cout<<dp[n]<<'\n';

    return 0;
}