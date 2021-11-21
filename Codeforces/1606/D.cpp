#include<bits/stdc++.h>
// #define SYNC_OFF
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
//short_type 
#define VE vector<int>
#define PI pair<int,int>
//
using namespace std;
// const int mod=998244353;
const int mod=1e9+7;
const int maxm=2e6+5;
char ans[maxm];
int idx[maxm];
int n,m;
void solve(){
    n=re,m=re;
    vector<VE>a(n+1,VE(m+1));
    vector<VE>lma(n+1,VE(m+1));
    vector<VE>rma(n+1,VE(m+1));
    vector<VE>lmi(n+1,VE(m+1));
    vector<VE>rmi(n+1,VE(m+1));
    ff(i,n){
        ff(j,m){
            a[i][j]=re;
        }
        ff(j,m){
            if(j==1)lma[i][j]=lmi[i][j]=a[i][j];
            else{
                lma[i][j]=max(lma[i][j-1],a[i][j]);
                lmi[i][j]=min(lmi[i][j-1],a[i][j]);
            }
        }
        rff(j,m){
            if(j==m)rma[i][j]=rmi[i][j]=a[i][j];
            else{
                rma[i][j]=max(rma[i][j+1],a[i][j]);
                rmi[i][j]=min(rmi[i][j+1],a[i][j]);
            }
        }
    }
    for(int k=1;k<m;k++){
        /*
        左边红>蓝
        右边蓝>红
        */
        ff(i,n)idx[i]=i;
        sort(idx+1,idx+1+n,[&](int i,int j){
            return lma[i][k]<lma[j][k];
        });
        //按lma[]排序
        //枚举左边蓝色最大值x=lma[i]
        //lma[1,i-1]<x,则lmi[1,i-1]<x,必须蓝色.
        //lma[i+1,n]>x,必须红色,否则违背了x为蓝色最大值.
        //然后判断左右两边是否合法即可.
        VE Lpma(n+1),Lsmi(n+1),Rpmi(n+1),Rsma(n+1);
        ff(i,n){
            int x=idx[i];
            Lpma[i]=lma[x][k];
            Rpmi[i]=rmi[x][k+1];
            Lsmi[i]=lmi[x][k];
            Rsma[i]=rma[x][k+1];
        }
        ff(i,n){
            if(i>1){
                Lpma[i]=max(Lpma[i],Lpma[i-1]);
                Rpmi[i]=min(Rpmi[i],Rpmi[i-1]);
            }
        }
        rff(i,n){
            if(i<n){
                Lsmi[i]=min(Lsmi[i],Lsmi[i+1]);
                Rsma[i]=max(Rsma[i],Rsma[i+1]);
            }
        }
        ff(i,n-1){
            if(Lpma[i]<Lsmi[i+1]&&Rpmi[i]>Rsma[i+1]){
                ac(1);
                for(int j=1;j<=n;j++){
                    int x=idx[j];
                    if(j<=i)ans[x]='B';
                    else ans[x]='R';
                }
                ans[n+1]=0;
                printf("%s %d\n",ans+1,k);
                return ;
            }
        }
    }
    ac(0);
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