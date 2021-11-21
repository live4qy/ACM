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
int a[maxm];
int b[maxm];
int x[maxm];
int n,m;
void cal(int bl,int br,int l,int r){
    
}
void solve(){
    n=re,m=re;
    ff(i,n)a[i]=re;
    ff(i,m)b[i]=re;
    //离散化
    int num=0;
    ff(i,n)x[++num]=a[i];
    ff(i,m)x[++num]=b[i];
    sort(all(x,num));
    num=unique(all(x,num))-x-1;
    ff(i,n)a[i]=lower_bound(all(x,num),a[i])-x;
    ff(i,m)b[i]=lower_bound(all(x,num),b[i])-x;
    /*
    首先,a内部的逆序对是固定的,这部分先不管.
    
    先对b[]排序,
    一个结论:b[]摆放的相对位置一定从小到大
    证明,设b中的两个数的位置为i和j,i<j且c[i]>c[j],
    如果交换位置,那么逆序对的变化量为:
    -小于c[i]的数量+大于c[i]的数量
    -大于c[j]的数量+小于c[j]的数量
    由于c[i]>c[j],那么有:
    (小于c[i]的数量)>(小于c[i]的数量)
    (大于c[i]的数量)<(大于c[j]的数量)
    可以推出交换之后逆序对的变化量<0,即交换后更优
    那么b[]摆放的相对位置一定从小到大.
    
    那么问题变为求b[]的摆放位置,使得逆序对总数最少.
    */
    sort(all(b,m));
    

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