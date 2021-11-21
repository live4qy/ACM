#include<bits/stdc++.h>
// #define SYNC_OFF
typedef std::vector<int> VE;
typedef std::pair<int,int> PI;
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
//
using namespace std;
// const int mod=998244353;
const int mod=1e9+7;
const int maxm=2e6+5;
int a[2][maxm<<2];
int cnt[2][22];
int n,q;
void pp(int p,int k,int node){
    if(a[p][node]!=-1)cnt[p][k]--;
    if(a[p][node*2]==a[p][node*2+1]){//奇偶性相同
        a[p][node]=a[p][node*2];
    }else{//奇偶性不同
        a[p][node]=-1;
    }
    if(a[p][node]!=-1)cnt[p][k]++;
}
void build(int p,int k,int l,int r,int node){
    a[p][node]=0;
    if(k>0)cnt[p][k]++;
    if(l==r)return ;
    int mid=(l+r)/2;
    build(p,k-1,l,mid,node*2);
    build(p,k-1,mid+1,r,node*2+1);
}
void upd(int p,int k,int v,int l,int r,int node){
    if(l==r){
        a[p][node]^=1;return ;
    }
    int mid=(l+r)/2;
    if(v<=mid)upd(p,k-1,v,l,mid,node*2);
    else upd(p,k-1,v,mid+1,r,node*2+1);
    pp(p,k,node);
}
void solve(){
    n=re,q=re;
    int tot=(1<<n);
    build(0,n,1,tot,1);
    build(1,n,1,tot,1);
    int num=0;//2^k的方块总数量,k>0
    for(int i=n,c=1;i>=1;i--,c*=4){
        num+=c;
    }
    while(q--){
        int op=re,x=re;
        upd(op,n,x,1,tot,1);
        int eq=0;//相同2^k块的数量(k>0)
        for(int i=1;i<=n;i++){
            eq+=cnt[0][i]*cnt[1][i];
        }
        int neq=num-eq;
        int ans=neq*4+1;
        pr(ans);pee;
    }
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