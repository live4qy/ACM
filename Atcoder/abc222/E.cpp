#include<bits/stdc++.h>
// #define MULTI_CASE
#define SYNC_OFF
#define PI pair<int,int>
#define ll long long
// #define int long long
using namespace std;
const int mod=998244353;
// const int mod=1e9+7;
const int maxm=1e3+5;
vector<PI>g[maxm];
int cnt[maxm];
int d[111111];
int a[maxm];
int n,m,k;
int dfs(int x,int fa,int y){
    if(x==y)return 1;
    for(auto i:g[x]){
        int v=i.first;
        if(v==fa)continue;
        if(dfs(v,x,y)){
            cnt[i.second]++;
            return 1;
        }
    }
    return 0;
}
void solve(){
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>a[i];
    }
    for(int i=1;i<n;i++){
        int x,y;cin>>x>>y;
        g[x].push_back({y,i});
        g[y].push_back({x,i});
    }
    //预处理每条边被经过多少次
    for(int i=1;i<m;i++){
        dfs(a[i],-1,a[i+1]);
    }
    //dp求方案数
    //d[i]表示B=i的方案数.
    int sum=0;
    for(int i=1;i<n;i++){
        sum+=cnt[i];
    }
    d[0]=1;
    for(int i=1;i<n;i++){
        for(int j=sum;j>=cnt[i];j--){
            d[j]=(d[j]+d[j-cnt[i]])%mod;
        }
    }
    //
    int ans=0;
    for(int i=0;i<=sum;i++){
        if(i-(sum-i)==k){
            ans=(ans+d[i])%mod;
        }
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