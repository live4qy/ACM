#include<bits/stdc++.h>
#define MULTI_CASE
#define SYNC_OFF
#define PI pair<int,int>
#define ll long long
// #define int long long
using namespace std;
// const int mod=998244353;
const int mod=1e9+7;
const int maxm=2e6+5;
vector<int>g[maxm];
int del[maxm];
int d[maxm];
int n,k;
void solve(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        g[i].clear();
        del[i]=0;
        d[i]=0;
    }
    for(int i=1;i<n;i++){
        int x,y;cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
        d[x]++;d[y]++;
    }
    queue<int>q;
    for(int i=1;i<=n;i++){
        if(d[i]<=1){
            q.push(i);
            del[i]=1;
        }
    }
    k--;
    while(q.size()&&k){
        int len=q.size();
        for(int i=0;i<len;i++){
            int x=q.front();q.pop();
            for(int v:g[x]){
                d[v]--;
                if(d[v]<=1&&!del[v]){
                    q.push(v);
                    del[v]=1;
                }
            }
        }
        k--;
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(!del[i])ans++;
    }
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