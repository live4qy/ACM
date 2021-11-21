#include<bits/stdc++.h>
#define MULTI_CASE
// #define SYNC_OFF
#define PI pair<int,int>
#define ll long long
// #define int long long
using namespace std;
// const int mod=998244353;
const int mod=1e9+7;
const int maxm=2e6+5;
vector<int>g[maxm];
set<int>s[maxm];
int idx[maxm];
int pre[maxm];
int ans[maxm];
int pos[maxm];
int nt[maxm];
int a[maxm];
int b[maxm];
int n;
int ffind(int x){
    return pre[x]==x?x:pre[x]=ffind(pre[x]);
}
bool cmp(int i,int j){
    return a[i]<a[j];
}
void merged(int x,int y){
    int fx=ffind(x),fy=ffind(y);
    if(fx==fy)return ;
    if(s[fx].size()<s[fy].size())swap(fx,fy);
    for(auto &i:s[fy])s[fx].insert(i);
    pre[fy]=fx;
}
void solve(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        g[i].clear();
    }
    for(int i=1;i<n;i++){
        int x,y;scanf("%d%d",&x,&y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    //离散化
    for(int i=1;i<=n;i++){
        b[i]=a[i];
    }
    sort(b+1,b+1+n);
    int num=unique(b+1,b+1+n)-b-1;
    for(int i=1;i<=n;i++){
        a[i]=lower_bound(b+1,b+1+num,a[i])-b;
    }
    for(int i=1;i<=n;i++){
        pos[a[i]]=i;
    }
    //
    for(int i=1;i<=n;i++){
        s[i].clear();
    }
    for(int x=1;x<=n;x++){
        s[x].insert(a[x]);
        for(int v:g[x]){
            s[x].insert(a[v]);
        }
    }
    for(int i=1;i<=n;i++){
        idx[i]=i;
    }
    sort(idx+1,idx+1+n,cmp);//从小到大排序
    for(int i=1;i<=n;i++){
        pre[i]=i;
        nt[i]=0;
    }
    for(int i=1;i<=n;i++){
        int x=idx[i];
        for(int v:g[x]){//能够到达的点
            if(a[v]<a[x]){
                merged(v,x);
            }
        }
        int fx=ffind(x);
        auto it=s[fx].upper_bound(a[x]);//找最小的
        if(it!=s[fx].end()){
            nt[x]=pos[*it];
        }
    }
    for(int i=n;i>=1;i--){
        int x=idx[i];
        if(!nt[x])ans[x]=1;
        else ans[x]=ans[nt[x]]+1;
    }
    for(int i=1;i<=n;i++){
        printf("%d\n",ans[i]);
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