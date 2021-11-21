#include<bits/stdc++.h>
#define MULTI_CASE
#define PI pair<int,int>
#define int long long
using namespace std;
const int maxm=2e6+5;
const int BIT_maxm=2e6+5;
struct BIT{
   int c[BIT_maxm];
   inline int lowbit(int i){return i&-i;}
   void add(int i,int t){while(i<BIT_maxm)c[i]+=t,i+=lowbit(i);}
   int ask(int i){int ans=0;while(i)ans+=c[i],i-=lowbit(i);return ans;}
}T;
int a[maxm];
int b[maxm];
int n;
void solve(){
    //init
    for(int i=1;i<=n;i++)T.add(a[i],-1);
    //
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b+1,b+1+n);
    int num=unique(b+1,b+1+n)-b-1;
    for(int i=1;i<=n;i++){
        a[i]=lower_bound(b+1,b+1+num,a[i])-b;
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        T.add(a[i],1);
        int l=T.ask(a[i]-1);
        int r=i-T.ask(a[i]);
        ans+=min(l,r);
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
    ios::sync_with_stdio(0);cin.tie(0);
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