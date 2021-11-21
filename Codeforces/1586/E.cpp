#include<bits/stdc++.h>
// #define SYNC_OFF
typedef std::vector<int> VE;
typedef std::pair<int,int> PI;
#define int long long
#define ll long long
#define ull unsigned long long
//fast-coding
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
VE g[maxm],gg[maxm];
int x[maxm],y[maxm];
int mp[maxm];
int d[maxm];
int n,m,q;
vector<int>temp;
void dfs1(int x,int fa){
    mp[x]=1;
    for(int v:g[x]){
        if(mp[v])continue;
        gg[x].push_back(v);
        gg[v].push_back(x);
        dfs1(v,x);
    }
}
int dfs2(int x,int fa,int y){
    if(x==y){
        temp.pss(y);
        return 1;
    }
    for(int v:gg[x]){
        if(v==fa)continue;
        if(dfs2(v,x,y)){
            temp.pss(x);
            return 1;
        }
    }
    return 0;
}
void solve(){
    n=re,m=re;
    ff(i,m){
        int x=re,y=re;
        g[x].pss(y);
        g[y].pss(x);
    }
    q=re;
    ff(i,q){
        x[i]=re,y[i]=re;
        d[x[i]]++;d[y[i]]++;    
    }
    int cnt=0;
    ff(i,n){
        if(d[i]%2){
            cnt++;
        }
    }
    if(cnt){
        ac(0);pr(cnt/2);pee;
    }else{
        ac(1);
        dfs1(1,-1);
        ff(i,q){
            temp.clear();
            dfs2(y[i],-1,x[i]);
            pr(SZ(temp));pee;
            for(auto t:temp){
                pr(t);eee;
            }
            pee;
        }
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