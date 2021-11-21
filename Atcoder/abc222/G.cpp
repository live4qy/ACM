#include<bits/stdc++.h>
#define MULTI_CASE
#define SYNC_OFF
#define PI pair<int,int>
#define ll long long
#define int long long
using namespace std;
// const int mod=998244353;
const int mod=1e9+7;
const int maxm=2e6+5;
int ppow(int a,int b,int mod){
    int ans=1%mod;a%=mod;
    while(b){if(b&1)ans=1ll*ans*a%mod;a=1ll*a*a%mod;b>>=1;}
    return ans;
}
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}
int k;
int phi(int n){
    int ans=n;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            while(n%i==0)n/=i;
            ans=ans/i*(i-1);
        }
    }
    if(n!=1)ans=ans/n*(n-1);
    return ans;
}
bool check(int n,int mod){
    return ppow(10,n,mod)==1;
}
void solve(){
    cin>>k;
    int M=9*k/gcd(9*k,2);
    int P=phi(M);
    set<int>s;
    for(int i=1;i*i<=P;i++){
        if(P%i==0){
            if(check(i,M)){
                s.insert(i); 
            }
            if(check(P/i,M)){
                s.insert(P/i);
            }
        }
    }
    if(s.size())cout<<*s.begin()<<endl;
    else cout<<-1<<endl;
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