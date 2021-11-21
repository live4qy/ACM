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
int pre[maxm];
int idx[maxm];
int cnt[maxm];
int mp[maxm];
int a[maxm];
int n;
int ffind(int x){
    return pre[x]==x?x:pre[x]=ffind(pre[x]);
}
bool cmp(int i,int j){
    return a[i]<a[j];
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<n;i++){
        int x,y;cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for(int i=1;i<=n;i++){
        idx[i]=i;
    }
    sort(idx+1,idx+1+n,cmp);//从小到大排序
    int ans=0;
    //计算每个数作为最大值的贡献
    for(int i=1;i<=n;i++){
        pre[i]=i;
        cnt[i]=1;
        mp[i]=0;
    }
    for(int i=1;i<=n;i++){
        int x=idx[i];
        mp[x]=1;
        int sum=1;//一开始只有x自己一个点
        for(int v:g[x]){
            if(mp[v]){
                ans+=cnt[ffind(v)]*sum*a[x];
                sum+=cnt[ffind(v)];
                cnt[x]+=cnt[ffind(v)];
                pre[ffind(v)]=x;
            }
        }
    }
    //计算每个数作为最小值的贡献 
    for(int i=1;i<=n;i++){
        pre[i]=i;
        cnt[i]=1;
        mp[i]=0;
    }
    for(int i=n;i>=1;i--){
        int x=idx[i];
        mp[x]=1;
        int sum=1;//一开始只有x自己一个点
        for(int v:g[x]){
            if(mp[v]){
                ans-=cnt[ffind(v)]*sum*a[x];
                sum+=cnt[ffind(v)];
                cnt[x]+=cnt[ffind(v)];
                pre[ffind(v)]=x;
            }
        }
    }
    //
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