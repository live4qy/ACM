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
const int BIT_maxm=1e6+5;
struct BIT{
    int c[BIT_maxm];
    inline int lowbit(int i){return i&-i;}
    void add(int i,int t){while(i<BIT_maxm)c[i]+=t,i+=lowbit(i);}
    int ask(int i){int ans=0;while(i)ans+=c[i],i-=lowbit(i);return ans;}
}T;
int x[maxm],y[maxm];
int a[maxm];
int b[maxm];
int m[maxm];
int n;
vector<int>g[maxm];
//hash
int num[maxm],cur;
int mp[maxm];
int getid(int x){
    if(!mp[x]){
        num[++cur]=x;
        mp[x]=cur;
    }
    return mp[x];
}
void init(){
    ff(i,cur){
        g[i].clear();
        int x=num[i];
        mp[x]=0;
    }
    cur=0;
    ff(i,n)x[i]=y[i]=0;
}
//
int M_ans;
int l[maxm],r[maxm];
bool cmp(int i,int j){
    return r[i]<r[j];
}
void check(int t){
    auto &temp=g[t];
    sort(ST(temp),ED(temp),cmp);
    int last=-1e18;
    fff(i,SZ(temp)){
        int idx=temp[i];
        int lc=l[idx];
        int rc=r[idx];
        if(lc>last){//一定不同
            M_ans++;last=rc;
        }
        //可以相同
        int t=a[idx]-last;
        x[idx]+=t;
        y[idx]+=m[idx]-t;
    }
}
void solve(){
    init();
    n=re;
    ff(i,n){
        a[i]=re,b[i]=re,m[i]=re;
    }
    ff(i,n){//可选区间
        l[i]=max(0LL,a[i]-m[i]);
        r[i]=a[i]-max(0LL,m[i]-b[i]);
    }
    ff(i,n){//分组
        int t=a[i]+b[i]-m[i];
        int id=getid(t);
        g[id].push_back(i);
    }
    M_ans=0;
    ff(i,cur){
        check(i);
    }
    pr(M_ans);pee;
    ff(i,n){
        pr(x[i]);eee;pr(y[i]);pee;
    }
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