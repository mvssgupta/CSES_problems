#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << " " << x << endl;
int n;
int dp[1000001];
int main()
{
    cin >> n;
    memset(dp, 0, sizeof(dp));
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int num = i;
        dp[i] = 1e9;
        while (num>0)
        {
            int k = num % 10;
            if (k!=0)
                dp[i] = min(dp[i], 1 + dp[i - k]);
            num /= 10;
        }
    }
    cout << dp[n] << endl;
    return 0;
}