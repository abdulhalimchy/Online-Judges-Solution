#include<bits/stdc++.h>
#define LL long long
#define MX 1002
#define mod 100000007
using namespace std;
LL limit[52], coins[52], dp[52][MX][22], n, k;

LL make(LL i, LL curAmount, LL cur) ///cur = number of coin[i] type coin is currently used.
{
    if(i>n)
    {
        if(curAmount==0)
            return 1;
        else
            return 0;
    }
    if(dp[i][curAmount][cur]!=-1)
        return dp[i][curAmount][cur];
    LL ret1=0, ret2=0;
    if((curAmount-coins[i]>=0) && (cur<limit[i]))
        ret1=make(i, curAmount-coins[i], cur+1);
    ret2=make(i+1, curAmount, 0);
    return dp[i][curAmount][cur]=(ret1+ret2)%mod;
}

int main()
{
    LL t;
    scanf("%lld", &t);
    for(LL p=1; p<=t; p++)
    {
        scanf("%lld %lld", &n, &k);

        //.......memset......
        for(LL i=0; i<=n; i++)
        {
            for(LL j=0; j<=k; j++)
            {
                for(LL k=0; k<=20; k++)
                    dp[i][j][k]=-1;
            }
        }

        for(LL i=1; i<=n; i++)
            scanf("%lld", &coins[i]);
        for(LL i=1; i<=n; i++)
            scanf("%lld", &limit[i]);
        printf("Case %lld: %lld\n", p, make(1, k, 0));
    }
    return 0;
}
