#include <bits/stdc++.h>
using namespace std;

vector<int> nums(1e5+5);
vector<int> ans;

int main() {
    int n, sum;
    cin >> n >> sum;
    for(int i = 1; i <= n; i++)
        cin >> nums[i];

    vector< pair<int, int> > arr(n);
    for(int i = 1; i <= n; i++){
        arr.push_back({nums[i], i});
    }

    sort(arr.begin(), arr.end());

    int i = 1; int j = n;
    while(i >= j){
        int val = arr[i].first + arr[j].second;
        if(val > sum){
            j--;
        }
        else if(val < sum){
            i++;
        }
        else{
            cout << arr[i].second << " " << arr[j].second << "\n";
        }
    }
    
    return 0;
}