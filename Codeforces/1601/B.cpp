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
vector<PI>g[maxm];
int a[maxm];
int b[maxm];
int rp[maxm];
int n;
void add(int x,int y,int z){
    g[x].push_back({y,z});
}
struct Tree{
    int a[maxm<<2],tot;
    void build(int l,int r,int node){
        if(l==r){
            a[node]=l+b[l];
            rp[l+b[l]]=l;
            return ;
        }
        a[node]=++tot;
        int mid=(l+r)/2;
        build(l,mid,node*2);
        build(mid+1,r,node*2+1);
        add(a[node],a[node*2],0);
        add(a[node],a[node*2+1],0);
    }
    void upd(int st,int ed,int p,int l,int r,int node){
        if(st<=l&&ed>=r){
            add(p,a[node],1);return ;
        }
        int mid=(l+r)/2;
        if(st<=mid)upd(st,ed,p,l,mid,node*2);
        if(ed>mid)upd(st,ed,p,mid+1,r,node*2+1);
    }
    void init(){
        tot=n;
    }
}T;
int d[maxm];
int mp[maxm];
int pre[maxm];
void dj(int st){
    priority_queue<PI,vector<PI>,greater<PI> >q;
    for(int i=0;i<=T.tot;i++){
        d[i]=1e9;
    }
    d[st]=0;
    q.push({d[st],st});
    while(q.size()){
        int x=q.top().second;q.pop();
        if(mp[x])continue;
        mp[x]=1;
        // cout<<x<<endl;
        for(auto i:g[x]){
            int v=i.first,w=i.second;
            if(d[v]>d[x]+w){
                d[v]=d[x]+w;
                pre[v]=x;
                q.push({d[v],v});
            }
        }
    }
}
void solve(){
    n=re;
    ff(i,n)a[i]=re;
    ff(i,n)b[i]=re;
    T.init();
    T.build(1,n,1);
    ff(i,n){
        if(i-a[i]<=0){//一步到
            add(i,0,1);
        }else{
            int l=i-a[i],r=i;
            if(l<=r){
                T.upd(l,r,i,1,n,1);
            }
        }
    }
    dj(n);
    int ans=d[0];
    if(ans==1e9){
        pr(-1);pee;return ;
    }
    stack<int>s;
    int x=0;
    while(x!=n){
        // cout<<x<<endl;
        if(x==0||rp[x]){
            s.push(rp[x]);
        }
        x=pre[x];   
    }
    pr(s.size());pee;
    while(s.size()){
        int x=s.top();s.pop();
        pr(x);
        eee;
    }
    pee;
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