#include<bits/stdc++.h>
// #define SYNC_OFF
#define int long long
#define ll long long
#define ull unsigned long long
//fast-coding
#define ST(x) x.begin()
#define ED(x) x.end()
#define RST(x) x.rbegin()
#define RED(x) x.end()
#define CL(x) x.clear();
#define all(a,n) a+1,a+1+n
#define ff(i,n) for(ll i=1;i<=n;i++)
#define rff(i,n) for(ll i=n;i>=1;i--)
#define fff(i,n) for(ll i=0;i<n;i++)
#define rfff(i,n) for(ll i=n-1;i>=0;i--)
#define SC(x) scanf("%s",x)
#define SL(x) strlen(x)
#define pss(a) push_back(a)
#define ps(a) push(a)
#define SZ(x) (int)x.size()
#define pee puts("");
#define eee putchar(' ');
#define re readdd()
#define pr(a) printtt(a)
int readdd(){int x=0,f=1;char c=getchar();//
while(!isdigit(c)&&c!='-')c=getchar();
if(c=='-')f=-1,c=getchar();
while(isdigit(c))x=x*10+c-'0',c=getchar();
return f*x;}
void printtt(int x){if(x<0)putchar('-'),x=-x;//
if(x>=10)printtt(x/10);putchar(x%10+'0');}
int gcd(int a,int b){return b==0?a:gcd(b,a%b);}//
int ppow(int a,int b,int mod){a%=mod;//
int ans=1%mod;while(b){if(b&1)ans=(long long)ans*a%mod;
a=(long long)a*a%mod;b>>=1;}return ans;}
bool addd(int a,int b){return a>b;}
int lowbit(int x){return x&-x;}
const int dx[4]={0,0,1,-1};
const int dy[4]={1,-1,0,0};
bool isdigit(char c){return c>='0'&&c<='9';}
bool Isprime(int x){
    for(int i=2;i*i<=x;i++)if(x%i==0)return 0;
    return 1;
}
void ac(int x){if(x)puts("YES");else puts("NO");}
//short_type 
#define VE vector<int>
#define PI pair<int,int>
//
using namespace std;
// const int mod=998244353;
const int mod=1e9+7;
const int maxm=2e6+5;
int p[maxm],c;
int np[maxm];
int ans[maxm];
int mu[maxm];
int pw[maxm];
int n,k;
void init(){
    mu[1]=1;
    for(int i=2;i<maxm;i++){
        if(!np[i]){
            mu[i]=-1;
            p[c++]=i;
        }
        for(int j=0;j<c;j++){
            if(p[j]*i>=maxm)break;
            np[p[j]*i]=1;
            mu[p[j]*i]=(i%p[j]==0?0:-mu[i]);
            if(i%p[j]==0)break;
        }
    }
}
void solve(){
    init();
    n=re,k=re;
    ff(i,k)pw[i]=ppow(i,n,mod);
    for(int d=1;d<=k;d++){
        for(int j=d;j<=k;j+=d){
            int v=mu[d]*pw[j/d];
            int l=j,r=min(l+d-1,k);
            ans[l]=(ans[l]+v)%mod;
            ans[r+1]=(ans[r+1]-v)%mod;
        }
    }
    ff(i,k)ans[i]=((ans[i]+ans[i-1])%mod+mod)%mod;
    int res=0;
    ff(i,k){
        res=(res+(ans[i]^i))%mod;
    }
    pr(res);pee;
}
void Main(){
    // #define MULTI_CASE
    #ifdef MULTI_CASE
    int T;cin>>T;while(T--)
    #endif
    solve();
}
void Init(){
    #ifdef SYNC_OFF
    ios::sync_with_stdio(0);cin.tie(0);
    #endif
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif
}
signed main(){
    Init();
    Main();
    return 0;
}