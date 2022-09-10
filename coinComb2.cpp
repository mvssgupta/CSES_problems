#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << " " << x << endl;
#define mod 1000000007
int dp[1000001][101];
int n, x;
int v[101];

//! giving TLE for large numbers , due to recursion stack overflow.
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
    dp[level][prev] = (rec(level + v[prev], prev)%mod + rec(level, prev + 1)%mod)%mod;

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
    rec(0, 0);
    cout<<dp[0][0];
    return 0;
}



