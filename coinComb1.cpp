#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << " " << x << endl;
#define  mod 1000000007
int n, x;
int arr[1000003];
int dp[1000003];
int ans(int level)
{
    if (level == 0)
        return 1;
    if (dp[level] != -1)
        return dp[level];
    dp[level] = 0;
    for (int i = 0; i < n; i++)
    {
        if ((level - arr[i]) >=0)
            dp[level] += ans(level - arr[i]);
        dp[level]%=mod;
    }
    return dp[level];
}
int main()
{
    cin >> n >> x;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    memset(dp, -1, sizeof(dp));
    cout<<ans(x)<<endl;
    return 0;
}