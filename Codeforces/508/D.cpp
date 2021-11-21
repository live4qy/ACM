#include<bits/stdc++.h>
// #define MULTI_CASE
#define SYNC_OFF
#define PI pair<int,int>
#define ll long long
// #define int long long
using namespace std;
// const int mod=998244353;
const int mod=1e9+7;
const int maxm=2e5+5;
stack<PI>g[maxm];
map<string,int>mp;int idx;
string s[maxm];
int mark[maxm];
int in[maxm];
int out[maxm];
stack<int>stk;
int n;
int get(string& s){
    if(!mp.count(s)){
        mp[s]=++idx;
    }
    return mp[s];
}
void dfs(int x){
    while(g[x].size()){
        PI t=g[x].top();g[x].pop();
        int v=t.first;
        int e=t.second;
        mark[e]=1;//标记访问过的边
        dfs(v);
        stk.push(e);
    }
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        string ls=s[i].substr(0,2);
        string rs=s[i].substr(1,2);
        int l=get(ls),r=get(rs);
        g[l].push({r,i});
        out[l]++;in[r]++;
    }
    int st=1;
    int ma=0,mi=0;
    for(int i=1;i<=idx;i++){
        int dif=out[i]-in[i];
        if(!dif)continue;
        else if(dif==1)ma++,st=i;
        else if(dif==-1)mi++;
        else{
            cout<<"NO"<<endl;return ;
        }
    }
    if(ma!=mi||ma>1){
        cout<<"NO"<<endl;return ;
    }
    dfs(st);
    for(int i=1;i<=n;i++){
        if(!mark[i]){//无解,连通块不唯一
            cout<<"NO"<<endl;return ;
        }
    }
    //拿方案
    string ans;
    while(stk.size()){
        string x=s[stk.top()];stk.pop();
        if(ans.size()){
            ans+=x[2];
        }else{
            ans=x;
        }
    }
    //
    cout<<"YES"<<endl;
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