#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << " " << x << endl;

#define mod 1000000007
int n, x;
char arr[1001][1001];
int dp[1001][1001];
char obst = '*';
int rec(int i, int j)
{
    if (i > n || j > n || arr[i][j] == obst)
        return 0;
    if ((i == n - 1) && (j == n - 1))
        return 1;
    if (dp[i][j] != -1)
        return dp[i][j];
    dp[i][j] = 0;
    dp[i][j] += rec(i + 1, j)%mod + rec(i, j + 1)%mod;
    return dp[i][j]%mod;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    memset(dp, -1, sizeof(dp));
    cout << rec(0, 0);
    return 0;
}