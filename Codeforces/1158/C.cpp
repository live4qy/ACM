#include<bits/stdc++.h>
// #define SYNC_OFF
typedef std::vector<int> VE;
typedef std::pair<int,int> PI;
// #define int long long
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
vector<int>g[maxm];
int pos[maxm];
int dfn[maxm];
int nt[maxm];
int d[maxm];
int a[maxm];
int n;
void add(int x,int y){
    g[x].push_back(y);
    d[y]++;
}
struct Tree{
    int a[maxm<<2],tot;
    void build(int l,int r,int node){
        if(l==r){
            a[node]=l;return ;
        }
        a[node]=++tot;
        int mid=(l+r)/2;
        build(l,mid,node*2);
        build(mid+1,r,node*2+1);
        add(a[node],a[node*2]);
        add(a[node],a[node*2+1]);
    }
    void upd(int st,int ed,int p,int l,int r,int node){
        if(st<=l&&ed>=r){
            add(p,a[node]);return ;
        }
        int mid=(l+r)/2;
        if(st<=mid)upd(st,ed,p,l,mid,node*2);
        if(ed>mid)upd(st,ed,p,mid+1,r,node*2+1);
    }
    void init(){
        ff(i,tot){
            d[i]=0;
            CL(g[i]);
        }
        tot=n;
    }
}T;
bool cmp(int i,int j){
    return dfn[i]>dfn[j];
}
bool topo(){
    queue<int>q;
    ff(i,T.tot){
        if(d[i]==0){
            q.push(i);
        }
    }
    int idx=0;
    while(q.size()){
        int x=q.front();q.pop();
        dfn[x]=++idx;
        for(int &v:g[x]){
            if(d[v]){
                d[v]--;
                if(d[v]==0){
                    q.push(v);
                }
            }
        }
    }
    ff(i,T.tot){
        if(d[i]!=0){
            return 0;
        }
    }
    ff(i,n){
        pos[i]=i;
    }
    sort(all(pos,n),cmp);
    ff(i,n){
        int p=pos[i];
        a[p]=i;
    }
    return 1;
}
void init(){
    T.init();
}
void solve(){
    n=re;
    init();
    ff(i,n)nt[i]=re;
    //n+1是不存在,-1是丢失
    T.build(1,n,1);
    ff(i,n){
        if(nt[i]==-1)continue;
        int l=i+1,r=nt[i]-1;
        //大的点向小的点连边
        if(l<=r){
            T.upd(l,r,i,1,n,1);
        }
        if(nt[i]!=n+1){
            add(nt[i],i);
        }
    }
    int ok=topo();
    if(!ok){
        pr(-1);pee;return ;
    }
    ff(i,n){
        pr(a[i]);eee;
    }
    pee;
}
void Main(){
    #define MULTI_CASE
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