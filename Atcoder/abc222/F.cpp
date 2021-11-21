#include<bits/stdc++.h>
// #define MULTI_CASE
#define SYNC_OFF
#define PI pair<int,int>
#define ll long long
#define int long long
using namespace std;
// const int mod=998244353;
const int mod=1e9+7;
const int maxm=2e6+5;
vector<PI>g[maxm];
PI d[maxm][2];
int f[maxm];
int a[maxm];
int b[maxm];
int c[maxm];
int n;
void dfs1(int x,int fa){
    for(auto i:g[x]){
        int v=i.first;
        if(v==fa)continue;
        dfs1(v,x);
        //v作为重点的代价为a[v]+i.second
        //v不作为终点的代价为d[v][0].first+i.second
        //因此v方向上的最优解为两者取max
        int val=max(a[v],d[v][0].first)+i.second;
        if(val>=d[x][0].first){
            d[x][1]=d[x][0];
            d[x][0]={val,v};
        }else if(val>=d[x][1].first){
            d[x][1]={val,v};
        }
    }
}
void dfs2(int x,int fa){
    for(auto i:g[x]){
        int v=i.first;
        if(v==fa)continue;
        //x不作为终点的代价为max(f[x],d[x][0].first)+i.second
        //x作为终点的代价为a[x]+i.second
        //因此v向上的最优解为两者取max
        if(d[x][0].second!=v){
            f[v]=max(a[x],max(f[x],d[x][0].first))+i.second;
        }else{
            f[v]=max(a[x],max(f[x],d[x][1].first))+i.second;
        }
        dfs2(v,x);
    }
}
//

void solve(){
    cin>>n;
    for(int i=1;i<n;i++){
        int x,y,z;cin>>x>>y>>z;
        g[x].push_back({y,z});
        g[y].push_back({x,z});
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs1(1,1);
    dfs2(1,1);
    for(int i=1;i<=n;i++){
        int ans=max(f[i],d[i][0].first);
        cout<<ans<<endl;
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