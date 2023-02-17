#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lim 10000007
#define pb push_back
#define S second
#define pb push_back
#define mp make_pair
#define INF 1e18
#define fr(i,j,k) for(ll i=j;i<=k;i++)
#define frd(i,j,k) for(ll i=j;i>=k;i--)
#define F first
#define sd(n) scanf("%lld",&n)
#define pd(n) printf("%lld\n",n)
#define db double
#define mod 1000000007
#define pii pair<ll,ll>
int main()
{
    ll n;
    cin>>n;
    ll mx;
    cin>>mx;
    ll mn=mx;
    ll a1=0,a2=0;
    n--;
    ll x;
    while(n--)
    {
        cin>>x;
        if(x>mx)
            a1++;
        if(x<mn)
            a2++;
        mx=max(mx,x);
        mn=min(mn,x);
    }
    cout<<a1<<" "<<a2<<endl;
}
