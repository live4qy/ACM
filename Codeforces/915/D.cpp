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
vector<int>g[maxm];
int deg[maxm];
int d[maxm];
int n,m;
bool check(int idx){
    for(int i=1;i<=n;i++){
        d[i]=deg[i];
    }
    d[idx]--;
    queue<int>q;
    for(int i=1;i<=n;i++){
        if(!d[i]){
            q.push(i);
        }
    }
    while(q.size()){
        int x=q.front();q.pop();
        for(int v:g[x]){
            if(d[v]){
                d[v]--;
                if(!d[v]){
                    q.push(v);
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(d[i]){
            return 0;
        }
    }
    return 1;
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y;cin>>x>>y;
        g[x].push_back(y);
        deg[y]++;
    }
    int ok=0;
    for(int i=1;i<=n;i++){
        if(deg[i]&&check(i)){//有入度才可以删
            ok=1;break;
        }
    }
    if(ok)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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