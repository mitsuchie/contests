#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <queue>
#include <map>
#include <algorithm>
#include <functional>
#include <string>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define REP(i,p,n) for(int i=p;i<n;++i)
#define rep(i,n) REP(i,0,n)

// typedef long long int ll;
typedef int ll;
typedef pair<ll,ll> pii;
typedef vector<ll>  vint;
typedef vector<pii> vpii;
typedef vector<vint> det1;
typedef vector<vpii> det2;

ll N, D;

const int MAXN = 200001;
ll A[MAXN];

struct UnionFind
{
    vector<ll> uf;
    // 親なし(-1)で初期化しておく
    void init(ll n){ uf.assign(n,-1); }
    // 親がいないなら自分を返す, 親がいたら経路圧縮して返す(root直下に繋ぐ)
    ll find(ll x){ return uf[x]<0 ? x : (uf[x]=this->find(uf[x])); }
    // 繋げようとする(union/予約後なんですよね,これが)
    bool connect(ll a, ll b)
    {
        a = this->find(a); // aのルートノード
        b = this->find(b); // bのルートノード
        if(a!=b){ uf[b]=a; return true; } // 新しくつなげた
        return false; // もうつながってる
    }

} uf;

struct Edge
{
    ll from, to, cost;

    Edge(){}
    Edge(ll _from, ll _to, ll _cost):from(_from), to(_to), cost(_cost){}
    void input(ll d=0){ cin>>from>>to>>cost; from-=d; to-=d; }
    void set(ll _from, ll _to,ll _cost){ from=_from; to=_to; cost=_cost; }

    const bool operator<(const Edge& e) const { return cost<e.cost; }
};

ll kruscal(int n, vector<Edge>& edges) // need (unionfind, edge)
{
    ll res = 0;

    sort(edges.begin(), edges.end());
    uf.init(n);

    rep(i,edges.size()) // 各辺に注目する(コストの小さい順)
    {
        if(uf.connect(edges[i].from, edges[i].to))
        {
            res+=edges[i].cost; // 連結成分でなければ辺を結ぶ
        }
    }

    return res;
}

int main()
{
    cin >> N >> D;
    rep(i, N) { cin >> A[i]; }

    vector<Edge> edges;

    REP(i, 0, N) REP(j, i + 1, N)
    {
        const ll cost = abs(i - j) * D + A[i] + A[j];
        edges.push_back(Edge(i, j, cost));
    }

    const ll ans = kruscal(N, edges);
    cout << ans << endl;

    return 0;
}
