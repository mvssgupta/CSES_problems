#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << " " << x << endl;

#define mod 1000000007
int n, x;
char arr[1001][1001];
int dp[1001][1001];
char obst = '*';

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    dp[n - 1][n - 1] = (arr[n - 1][n - 1] != obst) ? 1 : 0;
    for (int i = n - 1; i >= 0; i--)
        for (int j = n - 1; j >= 0; j--)
            if (arr[i][j] != obst && i < n && j < n)
                dp[i][j] += dp[i + 1][j] % mod + dp[i][j + 1] % mod;
    cout << dp[0][0] % mod << endl;
    return 0;
}