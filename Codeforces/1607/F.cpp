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
char s[2222][2222];
PI nt[2222][2222];
int d[2222][2222];
int mp[2222][2222];
int n,m;
int ansx,ansy,ansd;
void solve(){
    n=re,m=re;
    ff(i,n){
        SC(s[i]+1);
        ff(j,m){
            char c=s[i][j];
            int x=i,y=j;
            if(c=='L')y--;
            else if(c=='R')y++;
            else if(c=='U')x--;
            else if(c=='D')x++;
            nt[i][j]={x,y};
        }
    }
    ff(i,n){
        ff(j,m){
            mp[i][j]=0;
            d[i][j]=0;
        }
    }
    ansx=0,ansy=0,ansd=-1;
    ff(i,n){
        ff(j,m){
            if(!d[i][j]){
                vector<PI>path;
                int x=i,y=j;
                while(!(x<1||x>n||y<1||y>m||mp[x][y])){
                    path.push_back({x,y});  
                    mp[x][y]=2;
                    int nx=nt[x][y].first;
                    int ny=nt[x][y].second;
                    x=nx,y=ny;
                }
                //情况1:走出了边界
                if(x<1||x>n||y<1||y>m){
                    int cc=0;
                    while(path.size()){
                        int px=path.back().first;
                        int py=path.back().second;
                        mp[px][py]=1;
                        path.pop_back();
                        d[px][py]=++cc;
                    }
                }else if(mp[x][y]==2){//情况2:走出了一个环
                    int cir=0;
                    for(int i=(int)path.size()-1;i>=0;i--){
                        int px=path[i].first;
                        int py=path[i].second;
                        cir++;
                        if(px==x&&py==y)break;
                    }
                    while(path.size()){
                        int px=path.back().first;
                        int py=path.back().second;
                        mp[px][py]=1;
                        path.pop_back();
                        d[px][py]=cir;
                        if(px==x&&py==y)break;
                    }
                    int cc=cir;
                    while(path.size()){
                        int px=path.back().first;
                        int py=path.back().second;
                        mp[px][py]=1;
                        path.pop_back();
                        d[px][py]=++cc;
                    }
                }else if(mp[x][y]==1){//情况3:走到了已经访问过的点
                    int cc=d[x][y];
                    while(path.size()){
                        int px=path.back().first;
                        int py=path.back().second;
                        mp[px][py]=1;
                        path.pop_back();
                        d[px][py]=++cc;
                    }
                }
            }
            int cnt=d[i][j];
            if(cnt>ansd){
                ansd=cnt;
                ansx=i,ansy=j;
            }
        }
    }
    pr(ansx);eee;pr(ansy);eee;pr(ansd);pee;
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