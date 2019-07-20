#include<bits/stdc++.h>
#define ll long long
#define sz 6
using namespace std;
int mod, a1, b1, c1, a2, b2, c2, f0, f1, f2, g0, g1, g2;
ll fn=0, gn=0;
void multiply(ll a[][sz], ll b[][sz])
{
    ll mul[sz][sz];
    for (int i=0; i<sz; i++)
    {
        for (int j=0; j<sz; j++)
        {
            mul[i][j]=0;
            for (int k=0; k<sz; k++)
                mul[i][j]=(mul[i][j]+((a[i][k]*b[k][j])%mod))%mod;
        }
    }

    for (int i=0; i<sz; i++)
        for (int j=0; j<sz; j++)
            a[i][j] = mul[i][j]%mod;
}

void nth_power(ll m[][sz], int n)
{
    if(n==0 || n==1)
        return;
    ll temp[][sz]={{a1, b1, 0, 0, 0, c1}, {1, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 0, 0}, {0, 0, c2, a2, b2, 0}, {0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 1, 0}};
    nth_power(m, n/2);
    multiply(m, m);
    if(n%2==1)
        multiply(m, temp);
}

void cal_fngn(int n)
{
    if(n==0)
    {
        fn=f0;
        gn=g0;
        return;
    }
    else if(n==1)
    {
        fn=f1;
        gn=g1;
        return;
    }
    else if(n==2)
    {
        fn=f2;
        gn=g2;
        return;
    }

    ll m[][sz]={{a1, b1, 0, 0, 0, c1}, {1, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 0, 0}, {0, 0, c2, a2, b2, 0}, {0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 1, 0}};
    nth_power(m, n-2);

    fn=(m[0][0]*f2)%mod;
    fn+=(m[0][1]*f1)%mod;
    fn+=(m[0][2]*f0)%mod;
    fn+=(m[0][3]*g2)%mod;
    fn+=(m[0][4]*g1)%mod;
    fn+=(m[0][5]*g0)%mod;
    fn%=mod;

    gn=(m[3][0]*f2)%mod;
    gn+=(m[3][1]*f1)%mod;
    gn+=(m[3][2]*f0)%mod;
    gn+=(m[3][3]*g2)%mod;
    gn+=(m[3][4]*g1)%mod;
    gn+=(m[3][5]*g0)%mod;
    gn%=mod;

}

int main()
{
    int n, q, t;
    scanf("%d", &t);
    for(int i=1; i<=t; i++)
    {
        scanf("%d %d %d", &a1, &b1, &c1);
        scanf("%d %d %d", &a2, &b2, &c2);
        scanf("%d %d %d", &f0, &f1, &f2);
        scanf("%d %d %d", &g0, &g1, &g2);
        scanf("%d", &mod);
        scanf("%d", &q);
        printf("Case %d:\n", i);
        while(q--)
        {
            scanf("%d", &n);
            cal_fngn(n);
            printf("%lld %lld\n", fn%mod, gn%mod);
        }
    }
    return 0;
}
