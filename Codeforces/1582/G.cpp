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
const int maxm=1e6+5;
bool np[maxm];
VE fac[maxm];
char s[maxm];
int a[maxm];
VE pos[maxm];
int lc[maxm];//lc[i]表示i左边能到达i的最大起始点
int n;
void init(){//预处理质因子
    for(int i=2;i<maxm;i++){
        if(!np[i]){
            for(int j=i;j<maxm;j+=i){
                fac[j].push_back(i);
                np[j]=1;
            }
        }
    }
}
void add(int x,int id){
    int n=x;
    lc[id]=id;
    for(auto i:fac[x]){
        while(n%i==0){
            pos[i].push_back(id);
            n/=i;
        }
    }
}
void del(int x,int id){
    int n=x;
    lc[id]=id;
    for(auto i:fac[x]){
        while(n%i==0){
            if(pos[i].size()){
                pos[i].pop_back();
            }else{
                lc[id]=-1;//无解
            }
            n/=i;
        }
        if(pos[i].size()){
            lc[id]=min(lc[id],pos[i].back());
        }else{
            lc[id]=min(lc[id],0LL);//正好
        }
    }
}
void solve(){
    init();
    n=re;
    ff(i,n)a[i]=re;
    SC(s+1);
    ff(i,n){
        if(s[i]=='*')add(a[i],i);
        else if(s[i]=='/') del(a[i],i);
        else{
            assert(0);
        }
    }
    //debug
    cout<<"lc[]:"<<endl;
    ff(i,n){
        cout<<i<<' '<<lc[i]<<endl;
    }
    cout<<endl;
    //对于位置i,只有<=lc[i]的位置可以到达i
    //枚举r
    int ans=0;
    ff(i,n){
        
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