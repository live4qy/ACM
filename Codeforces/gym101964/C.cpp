
#include <bits/stdc++.h>
using namespace std;
const int maxm = 1e5 + 5;
vector<int> g[maxm];
int d[111][111];
int a[maxm];
int n, m;
int ans = 1e9;
void check(int e, int q){
    int dist = d[e][q];
    int cnt = 0;
    for (int i = 1; i <= n; i++){
        if (!a[i])continue;
        int ma = max(d[e][i], d[q][i]);
        if (ma <= dist){
            cnt++;
        }
    }
    if (cnt >= m){
        ans = min(ans, dist);
    }
}
void dfs(int x, int fa, int r){
    for (int v : g[x]){
        if (v == fa)
            continue;
        d[r][v] = d[r][x] + 1;
        dfs(v, x, r);
    }
}
void cal(int x){
    dfs(x, 0, x);
}
void solve(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    for (int i = 1; i < n; i++){
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    if (m == 1){
        cout << 0 << endl;
        return;
    }
    for (int i = 1; i <= n; i++){
        cal(i);
    }
    for (int i = 1; i <= n; i++){
        for (int j = i + 1; j <= n; j++){
            if (a[i] && a[j]){
                check(i, j);
            }
        }
    }
    cout << ans << endl;
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("../in.txt", "r", stdin);
#endif
    solve();
    return 0;
}