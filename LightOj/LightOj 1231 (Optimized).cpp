#include<bits/stdc++.h>
#define LL long long
#define MX 1002
#define mod 100000007
using namespace std;
LL limit[52], coins[52], dp[52][MX], n, k;

LL make(LL i, LL curAmount)
{
    if(i>n)
    {
        if(curAmount==k)
            return 1;
        else
            return 0;
    }
    if(dp[i][curAmount]!=-1)
        return dp[i][curAmount];
    LL ret=0;
    for(int j=0; j<=limit[i]; j++)
    {
        if(curAmount+(coins[i]*j)<=k)
        {
            ret+= make(i+1, curAmount+(coins[i]*j));
            ret%=mod;
        }
        else
            break;
    }
    return dp[i][curAmount]=ret;
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
                    dp[i][j]=-1;
            }
        }

        for(LL i=1; i<=n; i++)
            scanf("%lld", &coins[i]);
        for(LL i=1; i<=n; i++)
            scanf("%lld", &limit[i]);
        printf("Case %lld: %lld\n", p, make(1, 0));
    }
    return 0;
}
