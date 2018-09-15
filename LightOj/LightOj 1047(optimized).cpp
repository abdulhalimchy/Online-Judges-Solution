
#include<bits/stdc++.h>
#define MX 25
#define mn(a,b,c) min(a,min(b,c))
using namespace std;

int rgb[MX][5], n, dp[MX][5];

int main()
{
    int t;
    scanf("%d", &t);
    for(int p=1; p<=t; p++)
    {
        scanf("%d", &n);
        for(int i=1; i<=n; i++)
            for(int j=1; j<=3; j++)
                scanf("%d", &rgb[i][j]);

        dp[1][1]=rgb[1][1];
        dp[1][2]=rgb[1][2];
        dp[1][3]=rgb[1][3];
        for(int i=1; i<n; i++)
        {
            int temp;
            temp=min(dp[i][1], dp[i][2]);
            dp[i+1][3]=temp+rgb[i+1][3];
            temp=min(dp[i][2], dp[i][3]);
            dp[i+1][1]=temp+rgb[i+1][1];
            temp=min(dp[i][1], dp[i][3]);
            dp[i+1][2]=temp+rgb[i+1][2];
        }
        printf("Case %d: %d\n", p, mn(dp[n][1], dp[n][2], dp[n][3]));
    }
    return 0;
}
