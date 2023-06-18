#include<bits/stdc++.h>

using namespace std;

//Memorization method
const int N = 1e6;
int h[N];
int dp[N];

int stone(int n){
    if(n == 1) return 0;

    if(dp[n] != -1) return dp[n];

    int a1 = stone(n-1) + abs(h[n] - h[n-1]);
    int a2 = stone(n-2) + abs(h[n] - h[n-2]);
    dp[n] = min(a1, a2);

    return dp[n];
}

int main(){
    int n;
    cin >> n;

    for(int k=1; k<=n; k++)
        dp[k] = -1;

    for(int i=1; i<=n; i++)
        cin>>h[i];

    int ans = stone(n);
    cout<<ans<<"\n";
   

    return 0;
}