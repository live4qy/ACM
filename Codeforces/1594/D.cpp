#include<bits/stdc++.h>
#define MULTI_CASE
#define SYNC_OFF
#define PI pair<int,int>
// #define int long long
using namespace std;
// const int mod=998244353;
const int mod=1e9+7;
const int maxm=2e6+5;
int pre[maxm];
int cnt1[maxm];
int cnt2[maxm];
int n,m;
int ffind(int x){
    return pre[x]==x?x:pre[x]=ffind(pre[x]);
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n*2;i++)pre[i]=i;
    for(int i=1;i<=m;i++){
        int x,y;cin>>x>>y;
        char s[20];cin>>s;
        // cout<<x<<' '<<y<<' '<<s<<endl;
        if(s[0]=='i'){//x说y是假的
            pre[ffind(x)]=ffind(y+n);//如果x是真的,那y是假的
            pre[ffind(x+n)]=ffind(y);//如果x是假的,那y是真的
        }else{//x说y是真的
            pre[ffind(x)]=ffind(y);//如果x是真的,那y也是真的
            pre[ffind(x+n)]=ffind(y+n);//如果x是假的,那y也是假的
        }
    }
    for(int i=1;i<=n;i++){
        if(ffind(i)==ffind(i+n)){//无解
            cout<<-1<<endl;return ;
        }
    }
    int ans=0;
    for(int i=1;i<=n*2;i++){
        cnt1[i]=cnt2[i]=0;
    }
    for(int i=1;i<=n;i++){
        cnt1[ffind(i)]++;
    }
    for(int i=n+1;i<=n*2;i++){
        cnt2[ffind(i)]++;
    }
    for(int i=1;i<=n*2;i++){
        // cout<<i<<' '<<ffind(i)<<endl;
    }
    for(int i=1;i<=n;i++){
        if(pre[i]==i){
            int fake1=cnt2[ffind(i)];
            int fake2=cnt2[ffind(i+n)];
            ans+=max(fake1,fake2);
        }
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