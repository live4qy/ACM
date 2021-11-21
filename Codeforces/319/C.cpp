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
int d[maxm];
int a[maxm];
int b[maxm];
int n;
int que[maxm];
double cal(int j,int k){
    return (d[j]-d[k])*1.0/(b[j]-b[k]); 
}
void solve(){
    n=re;
    ff(i,n)a[i]=re;
    ff(i,n)b[i]=re;
    // 第一下肯定砍a[1],然后就可以用b[1]的代价充电了.
    // 之后的每次砍树一定是把整棵树砍掉
    // 由于b[n]=0,那么总目标等价于砍掉第n棵树.
    // 肯定是跳着砍的
    // 容易得出转移方程:
    // d[i]=min{d[j]+b[j]*a[i]}.
    // 设x=b[j],y=d[j],k=a[i]
    // y=kx+b
    // 单调栈维护点(b[j],d[j])形成的凸包
    // b[]单调递减
    // a[]单调递增
    int h=0,t=-1;
    d[1]=0;
    que[++t]=1;
    for(int i=2;i<=n;i++){
        //队头去掉劣解
        while(h<t&&cal(que[h],que[h+1])>-a[i]){
            h++;
        }
        //dp
        d[i]=d[que[h]]+b[que[h]]*a[i];
        //队尾插入i
        while(h<t&&cal(i,que[t-1])<cal(i,que[t])){
            t--;
        }
        que[++t]=i;
    }
    pr(d[n]);pee;
}
/*
n棵树,高度为a[].
每分钟能拒掉1单位的高度.

每分钟锯完后需要充电.
充电的费用取决于高度为0的树.
设高度为0的树的最大下标为i,
那么费用为b[i].

没有高度为0的树时不能充电.
一开始锯子充满了电.

已知条件:
a[1]<a[2]<a[3]....
b[1]>b[2]>b[3]....
b[n]=0且a[1]=1.

要求计算所有树全部砍完需要的最小花费.
n<=1e5,
1<=a[i]<=1e9
0<=b[i]<=1e9.
*/
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