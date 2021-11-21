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
vector<PI>g[maxm];
char s[maxm];
int odd[maxm];
int eve[maxm];
int n,q;
void solve(){
    cin>>(s+1);
    n=strlen(s+1);
    for(int i=1;i<=n;i++){
        odd[i]=eve[i]=0;
    }
    for(int i=1;i<=n;i++){
        if(s[i]=='('||s[i]==')'){
            if(i%2)odd[i]++;
            else eve[i]++;    
        }
    }
    for(int i=1;i<=n;i++){
        odd[i]+=odd[i-1];
        eve[i]+=eve[i-1];
    }
    cin>>q;
    for(int i=1;i<=q;i++){
        int l,r;cin>>l>>r;
        int o=odd[r]-odd[l-1];
        int e=eve[r]-eve[l-1];
        int ans=abs(o-e);
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