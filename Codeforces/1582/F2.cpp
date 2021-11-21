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
int d[5000+5][10000+5];
VE pos[maxm];
int a[maxm];
int n;
void solve(){
    n=re;ff(i,n)a[i]=re;
    ff(i,n)pos[a[i]].pss(i);
    for(int i=0;i<=5e3;i++){
        for(int j=0;j<=1e4;j++){
            d[i][j]=1e9;
        }
    }
    d[0][0]=0;
    /*
    d[i][j]表示子序列结尾<=i,能异或出j,结尾的最小下标
    转移:
    1.不选i作为结尾,那么d[i][j]=d[i-1][j]
    2.选i作为结尾,那么d[i][j]=(值为i的下标中,大于d[i-1][j^i]的最小下标),
    可以预处理pos[i]存所有i的下标,转移的时候二分就行了.
    
    总复杂度O(5e3*1e4*log),
    这个log小到可以忽略,因为pos中的数总数量为n.
    */
    ff(i,5e3){
        for(int j=0;j<=1e4;j++){
            //不选i作为结尾
            d[i][j]=d[i-1][j];
            if(!pos[i].size())continue;
            //选i作为结尾
            if((j^i)>1e4)continue;//5e3以内的数异或不会超过1e4
            int p=upper_bound(ST(pos[i]),ED(pos[i]),d[i-1][j^i])-ST(pos[i]);
            if(p!=SZ(pos[i])){
                d[i][j]=min(d[i][j],pos[i][p]);
            }
        }
    }
    VE ans;
    for(int j=0;j<=1e4;j++){
        if(d[(int)5e3][j]!=1e9){
            // cout<<j<<' '<<d[(int)5e3][j]<<endl;
            ans.pss(j);
        }
    }
    pr(SZ(ans));pee;
    for(auto i:ans){
        pr(i);eee;
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