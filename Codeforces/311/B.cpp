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
int f[111][111111];
int que[maxm];
int pre[maxm];
int d[maxm];
int h[maxm];
int t[maxm];
int x[maxm];
int n,m,p;
/*
m只猫,p个人
n座山,第i座山和第i-1座山的距离为d[i],人在山1位置.
第i只猫去山h[i]玩,玩到t[i]结束,然后原地等候.
人需要走到h[i]并带回猫,一个人可以同时带无限只猫.
最小化猫的等待时间之和.
1<=n,m<=1e5
1<=p<=100
*/
double cal(int pos,int i,int j){//点(k,d[i-1][k]+pre[k])
    return ((f[pos][i]+pre[i])-(f[pos][j]+pre[j]))*1.0/(i-j);
}
void solve(){
    n=re,m=re,p=re;
    for(int i=2;i<=n;i++)d[i]=re;
    for(int i=1;i<=m;i++)h[i]=re,t[i]=re;
    for(int i=1;i<=n;i++)d[i]+=d[i-1];//[1,i]的距离
    for(int i=1;i<=m;i++){//x[i]时刻出发恰好可以接到猫i
        x[i]=t[i]-d[h[i]];//x[i]+d[i]=t[i],x[i]=t[i]-d[i].
    }
    sort(x+1,x+1+m);
    for(int i=1;i<=m;i++){
        pre[i]=pre[i-1]+x[i];
    }
    //dp
    for(int j=1;j<=m;j++){
        f[1][j]=x[j]*j-pre[j];
    }
    for(int i=2;i<=p;i++){
        int h=0,t=-1;
        que[++t]=0;
        for(int j=1;j<=m;j++){
            //队头去掉劣解
            while(h<t&&cal(i-1,que[h],que[h+1])<=x[j])h++;
            //dp
            int k=que[h];
            f[i][j]=f[i-1][k]+x[j]*(j-k)-(pre[j]-pre[k]);
            //队尾插入j
            while(h<t&&cal(i-1,j,que[t])<cal(i-1,que[t],que[t-1]))t--;
            que[++t]=j;
        }
    }
    //
    int ans=f[1][m];
    for(int i=1;i<=p;i++){
        ans=min(ans,f[i][m]);
    }
    pr(ans);pee;
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