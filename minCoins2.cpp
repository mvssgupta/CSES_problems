#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << " " << x << endl;
int dp[101][101];
int n, x;
int v[101];
int rec(int level, int prev)
{
    // pruning
    if (level > x || prev >= n)
        return 0;

    // base case
    if (level == x)
        return 1;
    // cache check
    if (dp[level][prev] != -1)
        return dp[level][prev];

    // calculation
    // cout<<"Level "<<level<<" prev "<<prev<<endl;
    dp[level][prev] = rec(level + v[prev], prev) + rec(level, prev + 1);

    // return 
    return dp[level][prev];
}
int main()
{
    cin >> n >> x;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v, v + n);
    memset(dp, -1, sizeof(dp));
    cout << rec(0, 0) << endl;
    return 0;
}
