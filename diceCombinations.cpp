/* #include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
int main()
{
    int n;
    cin >> n;
    vector<long long> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n + 1; i++)
    {
        for (int x = 1; x <= 6; x++)
        {
            if (x > i)
                break;
            dp[i] = (dp[i] + dp[i - x]) % mod;
        }
    }
    cout << dp[n] << "\n";
    return 0;
}  */

#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << " " << x << endl;

int n;
int dp[1000001];
int rec(int level)
{
    // pruning
    //here this is a reduntant code , why because this case is 
    //already covered in calculation part as (level-i)>=0;
    // if (level < 0)
    //     return 0;

    // base case
    if (level == 0)
        return 1;

    // cache check
    if (dp[level] != -1)
        return dp[level];

    // calculation
    dp[level] = 0;
    for (int i = 1; i <= 6; i++)
    {
        if ((level - i) >= 0)
            dp[level] += rec(level - i);
    }

    // save and return
    return dp[level];
}
int main()
{
    cin >> n;
    memset(dp, -1, sizeof(dp));
    cout << rec(n);
    return 0;
}