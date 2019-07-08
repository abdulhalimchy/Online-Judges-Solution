///::::::::::::::::::::LightOj 1082 - Array Queries::::::::::::::::::::::

#include<bits/stdc++.h>
#define MX 100005
#define ll long long
using namespace std;
int mn[3*MX];
int ara[MX];

void build(int node, int L, int R)
{
    if(L==R)
    {
        mn[node]=ara[L];
        return;
    }
    int mid=(L+R)/2;
    build(node*2, L, mid);
    build(node*2+1, mid+1, R);
    mn[node]=min(mn[node*2], mn[node*2+1]);
}

int query(int node, int L, int R, int l, int r)
{
    if(r<L || R<l)
        return INT_MAX;
    if(L>=l && R<=r)
        return mn[node];
    int mid=(L+R)/2;
    int x=query(node*2, L, mid, l, r);
    int y=query(node*2+1, mid+1, R, l, r);
    return min(x, y);

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
            int l, r;
            scanf("%d %d", &l, &r);
            printf("%d\n", query(1, 1, n, l, r));
        }
    }

    return 0;
}
