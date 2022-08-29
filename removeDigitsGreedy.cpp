#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << " " << x << endl;
int n;
int main()
{
    cin >> n;
    int count=0;
    while(n>0)
    {
        int maxi=-1e9;
        int num=n;
        while (num>0)
        {
            int k = num % 10;
            maxi =max(maxi,k);
            num /= 10;
        }
        count++;
        n-=maxi;
    }
    cout << count << endl;
    return 0;
}