#include <bits/stdc++.h>
using namespace std;
int ans=-1, a[1005], b[1005], i, n, m, s, j;
int main()
{
    scanf("%d%d%d", &s, &n, &m);
    for(i=1; i<=n; ++i) scanf("%d", &a[i]);
    for(i=1; i<=m; ++i) scanf("%d", &b[i]);
    for(i=1; i<=n; ++i)
    for(j=1; j<=m; ++j)
        if(a[i]+b[j]<=s) ans = max(a[i]+b[j], ans);
    printf("%d\n", ans);
    return 0;
}
