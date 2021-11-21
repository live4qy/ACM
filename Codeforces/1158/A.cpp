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
int b[maxm];
int g[maxm];
int n,m;
void solve(){
    n=re,m=re;
    ff(i,n)b[i]=re;
    ff(i,m)g[i]=re;
    int ma=0;
    ff(i,n)ma=max(ma,b[i]);
    ff(i,m){
        if(ma>g[i]){//b[]最小值比最大值g[i]大,冲突
            pr(-1);pee;return ;
        }
    }
    set<PI>s;
    ff(i,n){
        s.insert({b[i],i});
    }
    int ans=0;
    ff(i,n)ans+=b[i]*m;
    map<int,int>mp;
    ff(i,m){
        int x=g[i];
        if(RST(s)->first>x){
            pr(-1);pee;return ;
        }
        //找<=x的数中,最接近x的
        while(1){
            auto it=s.upper_bound({x,mod});
            if(it==ST(s)){//没找到
                pr(-1);pee;
            }
            it--;
            if(it->first==x){//不用修改
                break;
            }
            if(mp[it->second]==m-1){
                s.erase({b[it->second],it->second});
            }else{
                ans+=x-(it->first);
                mp[it->second]++;
                break;
            }
        }
    }
    pr(ans);
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