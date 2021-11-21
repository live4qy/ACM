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
const int mod=998244353;
// const int mod=1e9+7;
const int maxm=2e6+5;
int pre[maxm];
int col[maxm];
char s[maxm];
VE g[maxm];
int n;
int ffind(int x){
    return pre[x]==x?x:pre[x]=ffind(pre[x]);
}
int dfs(int x,int c){
    col[x]=c;
    for(int v:g[x]){
        if(!col[v]){
            int f=dfs(v,-c);
            if(!f)return 0;
        }else if(col[v]==col[x]){
            return 0;
        }
    }
    return 1;
}
void add(int x,int y){
    g[ffind(x)].pss(ffind(y));
    g[ffind(y)].pss(ffind(x));
}
void med(int x,int y){
    pre[ffind(x)]=ffind(y);
}
int id1[maxm];
int id2[maxm];
int zero,one;
int num;
int cal(int k){//a[i]的最高位为k
    ff(i,num)pre[i]=i;
    //相同,并查集合并点
    for(int l=k,r=n;l<r;l++,r--){//a回文
        med(id1[l],id1[r]);
    }
    for(int l=1,r=n;l<r;l++,r--){//b回文
        med(id2[l],id2[r]);
    }
    ff(i,n){
        if(s[i]=='0'){
            med(id1[i],id2[i]);
        }
    }
    ff(i,k-1){//a[1,k-1]=0
        med(id1[i],zero);
    }
    med(id1[k],one);//a[k]=1
    med(id2[1],one);//b[1]=1
    //不同,建边
    ff(i,num)CL(g[i]);
    add(zero,one);
    ff(i,n){
        if(s[i]=='1'){
            add(id1[i],id2[i]);
        }
    }
    //计算答案
    ff(i,num)col[i]=0;
    int cnt=0;
    ff(i,num){
        if(pre[i]==i&&!col[i]){
            if(!dfs(i,1))return 0;
            cnt++;
        }
    }
    cnt--;//减去0和1所在的连通块,因为这个连通块只有一种选择.
    return ppow(2,cnt,mod);
}
void solve(){
    SC(s+1);
    n=SL(s+1);
    //由于a<b,s[1]=1
    //因此第一位a=0,b=1,之后不用考虑a<b这个条件了.
    //b的最高位确定了,a的还没确定.
    //要确定最高位是题目要求a满足忽略前导零后是回文.
    //考虑枚举a的最高位i,则a[1,i-1]必须是0
    //那么问题变为a的某些位和b的某些位必须相同,
    //或者a的某些位和b的某些位必须不同.
    //或者a的某些位和a的某些位必须相同.
    //就是2n个点,需要满足若干条件.
    ff(i,n)id1[i]=++num;
    ff(i,n)id2[i]=++num;
    zero=++num;
    one=++num;
    int ans=0;
    ff(i,n){
        if(i==1)continue;//a[1]不能为1,跳过.
        ans=(ans+cal(i))%mod;
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