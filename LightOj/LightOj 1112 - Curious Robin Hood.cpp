#include<bits/stdc++.h>
#define MX 100005
#define ll long long
using namespace std;
ll sum[3*MX];
ll poor;
int ara[MX];

void build(int node, int L, int R)
{
    if(L==R)
    {
        sum[node]=ara[L];
        return;
    }
    int mid=(L+R)/2;
    build(node*2, L, mid);
    build(node*2+1, mid+1, R);
    sum[node]=sum[node*2]+sum[node*2+1];
}

ll query(int node, int L, int R, int l, int r)
{
    if(r<L || R<l)
        return 0;
    if(L>=l && R<=r)
        return sum[node];
    int mid=(L+R)/2;
    ll x=query(node*2, L, mid, l, r);
    ll y=query(node*2+1, mid+1, R, l, r);
    return x+y;

}

void update(int node, int L, int R, int updateAt, int value, int type)
{
    if(updateAt<L || updateAt>R)
        return;
    if(L==R)
    {
        if(type==1)
        {
            poor=sum[node];
            sum[node]=0;
        }
        else
            sum[node]+=value;
        return;
    }

    int mid=(L+R)/2;
    if(updateAt<=mid)
        update(node*2, L, mid, updateAt, value, type);
    else
        update(node*2+1, mid+1, R, updateAt, value, type);

    sum[node]=sum[node*2]+sum[node*2+1];
}

int main()
{
    int t;
    scanf("%d", &t);
    for(int tt=1; tt<=t; tt++)
    {
        printf("Case %d:\n", tt);
        int n, q;
        scanf("%d %d", &n, &q);
        for(int i=1; i<=n; i++)
            scanf("%d", &ara[i]);
        build(1, 1, n);
        for(int i=1; i<=q; i++)
        {
            int type, l, r, v;
            scanf("%d", &type);
            if(type==1)
            {
                scanf("%d", &l);
                update(1, 1, n, l+1, 0, type);
                printf("%lld\n", poor);
            }
            else if(type==2)
            {
                scanf("%d %d", &l, &v);
                update(1, 1, n, l+1, v, type);
            }
            else
            {
                scanf("%d %d", &l, &r);
                printf("%lld\n", query(1, 1, n, l+1, r+1));
            }
        }
    }
    return 0;
}
