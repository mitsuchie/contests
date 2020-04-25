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
#include <tuple>
using namespace std;

#define REP(i,p,n) for(ll i=p;i<ll(n);++i)
#define rep(i,n) REP(i,0,n)

using ll = long long int;
using pll = pair<ll, ll>;

const ll mod = static_cast<ll>(1e9) + 7;

ll N, Q;

struct Edge
{
    ll to, color, cost;
};

const ll MAXN = 100000;
vector<Edge> G[MAXN];

ll X, Y, U, V;

bool vs[MAXN];

ll solve(ll now)
{
    vs[now] = true;

    for (ll i=0,n=G[now].size();i<n;++i)
    {
        const auto& e = G[now][i];
        if (vs[e.to]) { continue; }

        const ll cost = (e.color == X ? Y : e.cost);

        if (e.to == V)
        {
            return cost;
        }

        const ll res = solve(e.to);

        if (res != 0)
        {
            return res + cost;
        }
    }

    return 0;
}

int main()
{
    cin >> N >> Q;

    rep (i, N - 1)
    {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;

        --a;
        --b;

        G[a].push_back(Edge({b, c, d}));
        G[b].push_back(Edge({a, c, d}));
    }

    rep (i, Q)
    {
        cin >> X >> Y >> U >> V;

        fill(vs, vs + N, false);

        const ll res = solve(U);
        cout << res << endl;
    }

    return 0;
}
