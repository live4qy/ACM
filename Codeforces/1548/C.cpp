#include<bits/stdc++.h>
// #define MULTI_CASE
// #define SYNC_OFF
#define PI pair<int,int>
// #define int long long
using namespace std;
// const int mod=998244353;
const int mod=1e9+7;
const int maxm=6e6+5;
int n,q;
int d[maxm][3];
int fac[maxm],inv[maxm];
int ppow(int a,int b,int mod){
    int ans=1%mod;a%=mod;
    while(b){if(b&1)ans=1ll*ans*a%mod;a=1ll*a*a%mod;b>>=1;}
    return ans;
}
int C(int n,int m){
    if(m<0||m>n)return 0;
    return 1ll*fac[n]*inv[m]%mod*inv[n-m]%mod;
}
void C_init(){
    fac[0]=1;
    for(int i=1;i<maxm;i++)fac[i]=1ll*fac[i-1]*i%mod;
    inv[maxm-1]=ppow(fac[maxm-1],mod-2,mod);
    for(int i=maxm-2;i>=0;i--)inv[i]=1ll*inv[i+1]*(i+1)%mod;
}
void solve(){
    C_init();
    scanf("%d%d",&n,&q);
    d[0][0]=d[0][1]=d[0][2]=n+1;
    int inv3=ppow(3,mod-2,mod);
    for(int x=0;x<n*3;x++){
        d[x+1][0]=(1ll*C(3*n+3,x+2)-d[x][1]-2*d[x][0])%mod*inv3%mod;
        d[x+1][1]=(d[x+1][0]+d[x][0])%mod;
        d[x+1][2]=(d[x+1][1]+d[x][1])%mod;
    }
    for(int i=1;i<=q;i++){
        int x;scanf("%d",&x);
        int ans=d[x][0];
        ans=(ans%mod+mod)%mod;
        printf("%d\n",ans);
    }
}
void Main(){
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