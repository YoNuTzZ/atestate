#include <stdio.h>

using namespace std;

#define maxn 50010
#define maxm 250010
#define inf 1000000000

struct muchie
{
    long a, b, c;
} e[maxm];

long n, m, i, j, k, cost[maxn];

void init()
{
    long i;
    cost[1]=0;
    for(i=2; i<=n; i++)
        cost[i]=inf;
}

void solve()
{
    long i, j;
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            if(cost[e[j].a]+e[j].c<cost[e[j].b])
                cost[e[j].b]=cost[e[j].a]+e[j].c;
}   

long check_negativ()
{
    long i;
    for(i=1; i<=m; i++)
        if(cost[e[i].a]+e[i].c<cost[e[i].b])
            return 1;
    return 0;
}         

int main()
{
    freopen("bellmanford.in", "r", stdin);
    freopen("bellmanford.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for(i=1; i<=m; i++)
        scanf("%d%d%d", &e[i].a, &e[i].b, &e[i].c);
    init();
    solve();
    if(check_negativ())
    {
        printf("Ciclu negativ!\n");
        return 0;
    }
    for(i=2; i<=n; i++)
        printf("%d ", cost[i]);
    return 0;
}
    