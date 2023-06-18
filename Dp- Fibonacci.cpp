#include<bits/stdc++.h>

using namespace std;

const int N = 100 + 5;
long long ara[N];

long long fib(int n){
    if(n <= 2)
        return 1;

    if(ara[n] != -1){
        return ara[n];
    }

    ara[n] = fib(n-1) + fib(n-2);

    return ara[n];
}
/*
1 1 2 3 5 8 13
*/

int main(){
    int n;
    cin >> n;

    for(int i=0; i<=n; i++)
        ara[i] = -1;

    long long ans = fib(n);
    cout<<ans<<"\n";

    return 0;
}