#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << " " << x << endl;
#define INF 1e9
int main()
{
    int n,x;
    cin >> n >> x;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<int> dp(x + 1, INF);
    dp[0] = 0;
    for (int i = 1; i <= x; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i - v[j] >= 0)
                dp[i] = min(dp[i], dp[i - v[j]] + 1);
        }
    }
    for(int i=0;i<dp.size();i++)
    {
        cout<<dp[i]<<endl;
    }
    int ans = (dp[n] == INF) ? -1 : dp[x];
    cout << ans << endl;
    return 0;
}