#include<bits/stdc++.h>
#define MULTI_CASE
#define PI pair<int,int>
// #define int long long
using namespace std;
const int maxm=2e6+5;
int a[maxm];
int n;
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    vector<vector<int> >ans;
    for(int i=1;i<=n;i++){
        int mi=i;
        for(int j=i;j<=n;j++){
            if(a[j]<a[mi]){
                mi=j;
            }
        }
        if(mi==i)continue;
        int l=i,r=mi,d=mi-i;
        ans.push_back(vector<int>{l,r,d});
        vector<int>temp;
        for(int j=l;j<=r;j++){
            temp.push_back(a[j]);
        }
        for(int j=0;j<r-l+1;j++){
            a[(j-d+r-l+1)%(r-l+1)+l]=temp[j];
        }
    }
    cout<<ans.size()<<endl;
    for(auto i:ans){
        for(auto j:i)cout<<j<<' ';
        cout<<endl;
    }
}
void Main(){
    #ifdef MULTI_CASE
    int T;cin>>T;while(T--)
    #endif
    solve(),cout<<endl<<endl<<endl;
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