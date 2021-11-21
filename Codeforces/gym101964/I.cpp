#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxm=111+5;
vector<int>g[maxm];
int dfn[maxm];
int idx[maxm];
int deg[maxm];
int a[maxm];
int n,m;
bool cmp(int i,int j){
    return dfn[i]>dfn[j];
}
void topo(){
    queue<int>q;
    for(int i=1;i<=n;i++){
        if(!deg[i]){
            q.push(i);
        }
    }
    int num=0;
    while(q.size()){
        int x=q.front();q.pop();
        dfn[x]=++num;
        for(int v:g[x]){
            if(deg[v]){
                deg[v]--;
                if(!deg[v]){
                    q.push(v);
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        idx[i]=i;
    }
    sort(idx+1,idx+1+n,cmp);
    for(int i=1;i<=n;i++){
        int x=idx[i];
        a[x]=i;
    }
}
void add(int i,int j){
    g[i].push_back(j);
    deg[j]++;
}
int mp[maxm][maxm];
int r[maxm];
int f[maxm];
int cnt[maxm];
void solve(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y;cin>>x>>y;
        if(x>y)swap(x,y);
        mp[x][y]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(mp[i][j]){
                add(i,j);
            }else{
                add(j,i);
            }
        }
    }
    topo();
    r[n]=a[n];
    for(int i=n-1;i>=1;i--){
        r[i]=max(a[i],r[i+1]);
    }
    int ans=0;
    for(int i=1,mi=1e9;i<=n;i++){
        if(mi>a[i]){
            cnt[i]=1;
        }
        mi=min(mi,a[i]);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            if(a[j]>a[i])continue;
            int ok=1;
            for(int k=j+1;k<=i-1;k++){
                if(a[k]>a[j]&&a[k]<a[i]){//不能有(a[j],a[i])范围内的数
                    ok=0;
                }
            }
            if(ok)cnt[i]+=cnt[j];
        }
    }
    for(int j=1;j<=n;j++){
        if(j==n||r[j+1]<a[j]){
            ans+=cnt[j];
        }
    }
    cout<<ans<<endl;
}
signed main() {
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif
    solve();
    return 0;
}



