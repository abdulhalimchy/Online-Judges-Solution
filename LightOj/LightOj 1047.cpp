#include<bits/stdc++.h>
#define MX 25
#define mn(a,b,c) min(a,min(b,c))
using namespace std;

int rgb[MX][5], n, dp[MX][5];

int min_cost(int i, int j)
{
    if(i>n)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];

    int ans=INFINITY;
    for(int p=1; p<=3; p++)
    {
        if(p!=j)
        {
            ans=min(ans, min_cost(i+1, p));
        }
    }
    dp[i][j]=ans+rgb[i][j];
    return dp[i][j];
}

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
        memset(dp, -1, sizeof(dp));
        printf("Case %d: %d\n", p, mn(min_cost(1, 1), min_cost(1, 2), min_cost(1, 3)));
    }
    return 0;
}
