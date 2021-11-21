#include<bits/stdc++.h>
#define MULTI_CASE
#define PI pair<int,int>
// #define int long long
using namespace std;
const int maxm=2e5+5;
int a[maxm];
int n;
vector<PI>ans;
priority_queue<PI,vector<PI>,less<PI> >q;
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    while(q.size())q.pop();
    for(int i=1;i<=n;i++){
        if(a[i])q.push({a[i],i});
    }
    ans.clear();
    while(q.size()>=2){
        PI x=q.top();q.pop();
        PI y=q.top();q.pop();
        ans.push_back({x.second,y.second});
        x.first--;y.first--;
        if(x.first)q.push(x);
        if(y.first)q.push(y);
    }
    cout<<ans.size()<<endl;
    for(auto i:ans){
        cout<<i.first<<' '<<i.second;
        cout<<endl;
    }
    cout<<endl;
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