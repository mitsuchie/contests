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

ll N, K;

const ll MAXN = 100000;
vector<ll> G[MAXN];
bool visited[MAXN];

ll solve(ll p, ll d, ll v)
{
    visited[p] = true;

    ll ans = K - min(d, 2LL) - v;

    ll index = 0;

    for (ll i=0,n=G[p].size();i<n;++i)
    {
        const ll to = G[p][i];
        if (visited[to]) { continue; }

        const ll res = solve(to, d + 1, index);
        ++index;

        ans = (ans * res) % mod;
    }

    return ans % mod;
}

int main()
{
    cin >> N >> K;

    rep (i, N - 1)
    {
        ll a, b;
        cin >> a >> b;

        --a;
        --b;

        G[a].push_back(b);
        G[b].push_back(a);
    }

    const ll ans = solve(0, 0, 0);
    cout << ans << endl;

    return 0;
}
