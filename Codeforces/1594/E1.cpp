#include<bits/stdc++.h>
// #define MULTI_CASE
#define SYNC_OFF
#define PI pair<int,int>
#define int long long
using namespace std;
// const int mod=998244353;
const int mod=1e9+7;
const int maxm=2e6+5;
int lim[10][10];
int d[10][66];
int k;
/*
0是白 白黄
1是黄 白黄
2是绿 绿蓝
3是蓝 绿蓝
4是红 红橙
5是橙 红橙
*/
int dfs(int c,int k){
    if(k==1)return 1;
    if(d[c][k]!=-1)return d[c][k];
    d[c][k]=0;
    for(int i=0;i<6;i++){//左边的颜色
        if(lim[c][i])continue;
        for(int j=0;j<6;j++){//右边的颜色
            if(lim[c][j])continue;
            d[c][k]=(d[c][k]+dfs(i,k-1)*dfs(j,k-1)%mod)%mod;
        }
    }
    return d[c][k];
}
void init(){
    lim[0][0]=lim[0][1]=1;
    lim[1][0]=lim[1][1]=1;
    lim[2][2]=lim[2][3]=1;
    lim[3][2]=lim[3][3]=1;
    lim[4][4]=lim[4][5]=1;
    lim[5][4]=lim[5][5]=1;
}
void solve(){
    init();
    memset(d,-1,sizeof d);
    cin>>k;
    int ans=0;
    for(int i=0;i<6;i++){
        ans=(ans+dfs(i,k))%mod;
    }
    ans=(ans%mod+mod)%mod;
    cout<<ans<<endl;
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