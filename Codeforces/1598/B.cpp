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
int a[1111][6];
int n;
bool check(int x,int y){
    int c1=0,c2=0,c3=0;
    for(int i=1;i<=n;i++){
        if(a[i][x]&&a[i][y])c3++;
        else if(a[i][x])c1++;
        else if(a[i][y])c2++;
        else return 0;
    }
    if(c1>n/2||c2>n/2)return 0;
    return 1;
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=5;i++){
        for(int j=i+1;j<=5;j++){
            if(check(i,j)){
                cout<<"YES"<<endl;
                return ;
            }
        }
    }
    cout<<"NO"<<endl;
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