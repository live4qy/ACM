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
int ans[maxm];
int a[maxm];
int n;
int ask(){
    cout<<"?";
    for(int i=1;i<=n;i++){
        cout<<' '<<a[i];
    }
    cout<<endl;
    int x;cin>>x;
    return x;
}
void print(){
    cout<<"!";
    for(int i=1;i<=n;i++){
        cout<<' '<<ans[i];
    }
    cout<<endl;
}
void solve(){
    cin>>n;
    int pos=-1;
    //n次求出a[n]
    for(int i=1;i<n;i++){//这里最多循环到n-1
        for(int j=1;j<=n;j++)a[j]=1;
        a[n]=i+1;
        int x=ask();
        if(!x){//a[n]+(i+1)=n+2,那么a[n]=(n+2)-(i+1).
            ans[n]=(n+2)-(i+1);
            break;
        }
    }
    if(!ans[n])ans[n]=1;//n-1还无解,那么a[n]+(n-1)+1=n+1,因此a[n]=1.
    //每个数和ans[n]的差值范围在[1-ans[n],n-ans[n]]
    for(int dif=1-ans[n],c=1;dif<=n-ans[n];dif++,c++){//枚举dif求位置
        if(!dif)continue;
        for(int j=1;j<=n;j++)a[j]=n;
        a[n]=n+dif;
        if(n+dif>n){//最大值超过n,修正为n.
            int t=(n+dif)-n;
            for(int j=1;j<=n;j++)a[j]-=t;
        }
        int x=ask();
        ans[x]=c;
    }
    print();
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