#include<bits/stdc++.h>
#define MX 10005
#define mod 10000007
using namespace std;

int a, b, c, d, e, f;
int dp[MX];
int fn( int n ) {
    if( n == 0 ) return a%mod;
    if( n == 1 ) return b%mod;
    if( n == 2 ) return c%mod;
    if( n == 3 ) return d%mod;
    if( n == 4 ) return e%mod;
    if( n == 5 ) return f%mod;
    int temp=0;
    if(dp[n-1]!=-1)
    {
        temp+=dp[n-1];
        temp=temp%mod;
    }
    else
    {
        dp[n-1]=fn(n-1)%mod;
        temp+=dp[n-1];
        temp=temp%mod;
    }
    if(dp[n-2]!=-1)
    {
        temp+=dp[n-2];
        temp=temp%mod;
    }
    else
    {
        dp[n-2]=fn(n-2)%mod;
        temp+=dp[n-2];
        temp=temp%mod;
    }
    if(dp[n-3]!=-1)
    {
        temp+=dp[n-3];
        temp=temp%mod;
    }
    else
    {
        dp[n-3]=fn(n-3)%mod;
        temp+=dp[n-3];
        temp=temp%mod;
    }
    if(dp[n-4]!=-1)
    {
        temp+=dp[n-4];
        temp=temp%mod;
    }
    else
    {
        dp[n-4]=fn(n-4)%mod;
        temp+=dp[n-4];
        temp=temp%mod;
    }
    if(dp[n-5]!=-1)
    {
        temp+=dp[n-5];
        temp=temp%mod;
    }
    else
    {
        dp[n-5]=fn(n-5)%mod;
        temp+=dp[n-5];
        temp=temp%mod;
    }
    if(dp[n-6]!=-1)
    {
        temp+=dp[n-6];
        temp=temp%mod;
    }
    else
    {
        dp[n-6]=fn(n-6)%mod;
        temp+=dp[n-6];
        temp=temp%mod;
    }
    dp[n]=temp;
    return dp[n];
}
int main() {
    int n, caseno = 0, cases;
    scanf("%d", &cases);
    while( cases-- ) {
            memset(dp, -1, sizeof(dp));
        scanf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &n);
        printf("Case %d: %d\n", ++caseno, fn(n) % 10000007);
    }
    return 0;
}
