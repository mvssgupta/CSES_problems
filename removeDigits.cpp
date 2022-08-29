#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << " " << x << endl;
int n;
int arr[1000001];
int dp[1000001];
int rec(int i)
{
    if (i == 0)
        return 0;
    if (dp[i] != -1)
        return dp[i];
    int num = i;
    dp[i] = 1e9;
    while(num)
    {
        int k = num % 10;
        dp[i] = min(dp[i], 1 + rec(i - k));
        num/=10;
    }
    return dp[i];
}
int main()
{
    cin >> n;
    memset(dp, -1, sizeof(dp));
    cout << rec(n) << endl;
    return 0;
}