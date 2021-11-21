/*
这份没用__int128，防爆longlong用的是快速乘
可以处理出所有质因子
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxm = 2e5 + 5;
ll temp[maxm], cnt; //存所有质因子
//板子:
ll gcd(ll a, ll b)
{
    return b ? gcd(b, a % b) : a;
}
inline ll quick_mult(ll x, ll y, ll mod) {
  return (x * y - (ll)((long double)x / mod * y) * mod + mod) % mod;
}
ll quick_pow(ll a, ll n, ll mod)
{
    ll ans = 1;
    while (n){
        if (n & 1)
            ans = quick_mult(ans, a, mod);
        a = quick_mult(a, a, mod);
        n >>= 1;
    }
    return ans;
}
bool miller_rabin(ll n)
{
    if (n == 2)
        return true;
    if (n < 2 || !(n & 1))
        return false;
    ll s = 0, d = n - 1;
    while (!(d & 1))
    {
        d >>= 1;
        s++;
    }
    for (int i = 1; i <= 11; i++)
    {
        ll a = rand() % (n - 2) + 2;
        ll now = quick_pow(a, d, n), pre = now;
        for (int j = 1; j <= s; j++)
        {
            now = quick_mult(now, now, n);
            if (now == 1 && pre != 1 && pre != n - 1)
                return false;
            pre = now;
        }
        if (now != 1)
            return false;
    }
    return true;
}
ll pollard_rho(ll n, int c)
{
    ll x, y, i = 1, k = 2;
    x = y = rand() % (n - 2) + 2;
    for (;;)
    {
        i++;
        x = (quick_mult(x, x, n) + c) % n;
        ll g = gcd(y - x, n);
        if (g > 1 && g < n)
            return g;
        if (x == y)
            return n;
        if (i == k)
            y = x, k <<= 1;
    }
}
void find_fac(ll n, int k)
{
    if (n == 1)
        return;
    if (miller_rabin(n)){
        temp[++cnt] = n;
        return;
    }
    ll p = n;
    int c = k;
    while (p >= n)
        p = pollard_rho(p, c--);
    find_fac(p, k);
    find_fac(n / p, k);
}
//
ll a[maxm];
int n;
map<ll,vector<int> >mp;
int main(){
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    for(int i=1;i<=n;i++){
        cnt=0;
        find_fac(a[i],12345);
        if(!cnt)continue;
        sort(temp+1,temp+1+cnt);
        for(int j=1;j<=cnt;j++){
            if(temp[j]!=temp[j-1]){
                mp[temp[j]].push_back(i);
            }
        }
    }
    int ans=0;
    for(auto &i:mp){
        int last=0;
        int len=0;
        for(auto &p:i.second){
            if(p==last+1)len++;
            else{
                ans^=len;
                len=1;
            }
            last=p;
        }
        ans^=len;
    }
    if(ans)puts("First");
    else puts("Second");
    return 0;
}