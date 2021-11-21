#include<bits/stdc++.h>
#define MULTI_CASE
#define PI pair<int,int>
// #define int long long
using namespace std;
const int maxm=2e6+5;
int a[maxm];
int n,d;
void solve(){
    cin>>n>>d;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int ans=-1;
    queue<int>q;
    for(int i=0;i<n;i++){
        if(!a[i])q.push(i);
    }
    while(q.size()){    //bfs
        int len=q.size();
        ans++;
        for(int i=0;i<len;i++){
            int x=q.front();q.pop();
            int pre=(x-d+n)%n;
            if(a[pre]){
                a[pre]=0;
                q.push(pre);
            }
        }
    }
    for(int i=0;i<n;i++){
        if(a[i]){
            cout<<-1<<endl;return ;
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