#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << " " << x << endl;
int dp[1000001];
int n, x;
int v[1000001];
int rec(int level)
{
    if (level == 0)
        return 0;
    if (dp[level] != -1)
        return dp[level];
    dp[level] = 1e9;
    for (int i = 0; i < n; i++)
    {
        if ((level - v[i]) >= 0)
            dp[level] = min(dp[level], rec(level - v[i]) + 1);
    }

    return dp[level];
}
int main()
{
    cin >> n >> x;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    memset(dp, -1, sizeof(dp));
    int ans = rec(x);
    cout<<((ans!=1e9)?ans:-1)<<endl;
    return 0;
}
