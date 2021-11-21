#include<bits/stdc++.h>
using namespace std;
#define ing long long
#define PI pair<int,int>
const int maxm=2e5+5;
int dep[maxm];
int p3[maxm];
int a[maxm];
int n,k;
void ask(int x){
    cout<<x<<endl;
    string s;cin>>s;
    if(s[0]=='E')exit(0);
    for(int i=1;i<=n;i++){
        int t;cin>>t;
        if(!a[i])continue;
        if(s[0]=='<'&&a[i]<=x){
            dep[i]--;
            a[i]=t;
        }else if(s[0]=='>'&&a[i]>=x){
            dep[i]--;
            a[i]=t;
        }
    }
}
int getmid(){
    vector<PI>temp;
    int sum=0;
    for(int i=1;i<=n;i++){
        if(a[i]){
            temp.push_back({a[i],p3[dep[i]]});
            sum+=p3[dep[i]];
        }
    }
    sort(temp.begin(),temp.end());
    int v=-1;
    int mi=1e18;
    int ns=0;
    for(auto i:temp){
        int lc=ns,rc=sum-ns-i.second;
        if(abs(lc-rc)<mi){
            mi=abs(lc-rc);
            v=i.first;
        }
        if(ns+i.second>sum-ns){
            return i.first;
        }
        ns+=i.second;
    }
    return v;
}
void init(){
    p3[0]=1;
    for(int i=1;i<=10;i++)p3[i]=p3[i-1]*3;
}
void solve(){
    init();
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        dep[i]=k;
    }
    while(1){
        int mid=getmid();
        ask(mid);
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    #ifndef ONLINE_JUDGE
    // freopen("../in.txt","r",stdin);
    // freopen("../out.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);
    solve();
    return 0;
}