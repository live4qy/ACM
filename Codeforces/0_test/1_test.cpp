#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#define mod 1000000007


using namespace std;
typedef long long LL;

const int maxn = 50005;
const int sz = 17;
int a[1 << sz], b[1 << sz], nop[maxn];
int N, inv2;

LL inv(LL i)//求逆元
{
    if(i == 1)
        return 1;
    return (mod - mod / i) * inv(mod % i) % mod;
}

void is_p()
{
    nop[1] = 1;//nop=1表示不是质数
    for(int i = 2; i < maxn; i++)
    {
        if(!nop[i])
        {
            for(int j = 2 * i; j < maxn; j += i)
                nop[j] = 1;
        }
    }
    inv2 = inv(2);
}

void FWT(int * a, int opt)
{
    for(int i = 1; i < N; i <<= 1)
        for(int j = 0, p = i << 1; j < N; j += p)
            for(int k = 0; k < i; k++)
            {
                int x = a[j + k], y = a[i + j + k];
                a[j + k] = (x + y) % mod;
                a[i + j + k] = (x - y + mod) % mod;
                if(opt)
                    a[j + k] = 1LL * a[j + k] * inv2 % mod, a[i + j + k] = 1LL * a[i + j + k] * inv2 % mod;
            }
}

void qpow(int * ans, int * a, int p)//快速幂
{
    FWT(ans, 0), FWT(a, 0);
    while(p)
    {
        if(p & 1)
        {
            for(int i = 0; i < N; i++)
                ans[i] = 1LL * ans[i] * a[i] % mod;
        }
        for(int i = 0; i < N; i++)
            a[i] = 1LL * a[i] * a[i] % mod;
        p >>= 1;
    }
    FWT(ans, 1);
}



int main()
{
    is_p();
    int n, m;
    while(~scanf("%d%d", &n, &m))
    {
        for(N = 1; N < m; N <<= 1);
        N <<= 1;
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        for(int i = 1; i <= m; i++)
            if(!nop[i])
            a[i] = b[i] = 1;
        qpow(a, b, n - 1);
        printf("%d\n", a[0]);
    }
    return 0;
}

