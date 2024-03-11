#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;

#define f first
#define s second

//checa que tus constantes coincidan con el problema
const ll MAXN = 1e5+5;
const ll MAXLG = 25;
const ll INF = 1e7+5;
const ll MOD = 998244353;
const ll SQ = 500;

pair<ll,ll> LCA[MAXN][MAXLG];
ll H[MAXN];
vector<vector<pair<ll,ll>>> g;

ll lift(ll a, ll d, ll &mx) {
    ll idx = 0;
    while (d>0) {
        if (d%2 == 1) {
            mx = max(mx,LCA[a][idx].s);
            a = LCA[a][idx].f;
        }
        d = d/2;
        idx++;
    }
    return a;
}

pair<ll,ll> lca(ll a, ll b) {
    ll mx = 0;
    if (H[b] > H[a]) swap(a,b);
    a = lift(a,H[a]-H[b],mx);
    if (a == b) return {a,mx};
    for (int i=MAXLG-1;i>=0;i--) {
        if (LCA[a][i].f != LCA[b][i].f) {
            mx = max({mx,LCA[a][i].s,LCA[b][i].s});
            a = LCA[a][i].f;
            b = LCA[b][i].f;
        }
    }
    mx = max({mx,LCA[a][0].s,LCA[b][0].s});
    return {LCA[a][0].f,mx};
}

void dfs(ll nodo, ll p, ll d) {
    if (nodo != 1) H[nodo] = H[p]+1;
    else H[nodo] = 1;
    LCA[nodo][0] = {p,d};
    for (int i=1;i<MAXLG;i++) LCA[nodo][i] = {LCA[LCA[nodo][i-1].f][i-1].f,max(LCA[nodo][i-1].s,LCA[LCA[nodo][i-1].f][i-1].s)};
    for (int i=0;i<g[nodo].size();i++) {
        if (g[nodo][i].f != p) dfs(g[nodo][i].f,nodo,g[nodo][i].s);
    }
    return;
}


int main() {
ios_base::sync_with_stdio(0);cin.tie(0);
srand(time(0));
freopen("sub3.10.in", "w", stdout);
ll n = 10000, m = 20000, q = 10000;
cout<<n<<" "<<m<<"\n";
g.resize(n+2);
vector<pair<pair<ll,ll>,ll>> v;
set <pair<ll,ll>> st;
for (ll i=2;i<=n;i++) {
    ll r = rand()%(i-1)+1, r2 = rand()%INF+1;
    g[i].push_back({r,r2});
    g[r].push_back({i,r2});
    v.push_back({{i,r},r2});
    st.insert({min(i,r),max(i,r)});
}
/*
for (ll nodo=1;nodo<=n;nodo++) {
    ll r2 = rand()%INF+1;
    H[nodo] = nodo;
    LCA[nodo][0] = {max(nodo-1,1ll),r2};
    for (int i=1;i<MAXLG;i++) LCA[nodo][i] = {LCA[LCA[nodo][i-1].f][i-1].f,max(LCA[nodo][i-1].s,LCA[LCA[nodo][i-1].f][i-1].s)};
    if (nodo != n) {
        v.push_back({{nodo,nodo+1},r2});
    st.insert({nodo,nodo+1});
    }
}
*/
dfs(1,1,0);
while (v.size() != m) {
    ll r = rand()%(n)+1, r2, r3 = rand()%(n)+1;
    while (r == r3) r3 = rand()%(n)+1;
    if (st.find({min(r,r3),max(r,r3)}) != st.end()) continue;
    r2 = 1+lca(r,r3).s;
    g[r3].push_back({r,r2});
    g[r].push_back({r3,r2});
    v.push_back({{r3,r},r2});
    st.insert({min(r3,r),max(r3,r)});
}
random_shuffle(v.begin(),v.end());
for (int i=0;i<m;i++) cout<<v[i].f.f<<" "<<v[i].f.s<<" "<<v[i].s<<"\n";
cout<<q<<"\n";
for (int i=0;i<q;i++) {
    ll r = rand()%(n)+1, r3 = rand()%(n)+1;
    while (r == r3) r3 = rand()%(n)+1;
    cout<<r<<" "<<r3<<"\n";
}
return 0;
}
