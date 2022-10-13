#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvp vector<vector<pii>>
int mod=1e9+7;

int n, m, sn, en, one=1;
vi edge;
vvp g;

int dfs(int node, int p, int mask, vvi &dp, int setbits){
    if(mask == (one<<n)-1){
        return 1;
    }
    if(dp[node-1][mask] != -1){
        return dp[node-1][mask];
    }
    int ans = (setbits>1)?1:0;
    for(auto x:g[node]){
        int neigh = x.first;
        if(neigh == p){
            continue;
        }
        if((mask>>(neigh-1))&1){
        }else{
            ans += dfs(neigh, node, mask|(one<<(neigh-1)), dp, setbits+1);
        }
    }
    return dp[node-1][mask] = ans;
}

void solve()
{
    cin>>n>>m;
    g = vvp(n+1);
    edge = vi(n+1);
    for(int i=0; i<m; i++){
        int u, v, w=1;
        // cin>>u>>v>>w;
        cin>>u>>v;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
        if(u == 1 || v == 1){
            edge[u*v] = 1;
        }
    }
    vvi dp(n, vi(one<<n, -1));
    int ans = 0;
    for(int i=1; i<=n; i++){
        ans += dfs(1, 0, 1, dp, 1);
    }
    cout<<"Number of Simple Paths [path abcd and dcba are different] = "<<ans<<endl;
}

#undef int

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    // int _t; cin>>_t; while(_t--)
    solve();
}