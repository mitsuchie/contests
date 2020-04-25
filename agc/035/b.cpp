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

ll N, M;

const ll MAXN = 100000;
vector<pll> G[MAXN];

bool v1[MAXN];
bool v2[MAXN];

bool e1[MAXN];
bool e2[MAXN];

ll solve(ll p)
{
    if (v1[p]) { return 0; }
    v1[p] = true;

    ll res = 0;

    for (const auto& t : G[p])
    {
        const auto q = t.first;
        const auto e = t.second;

        if (e1[e]) { continue; }
        e1[e] = true;

        res += solve(q) + 1;
    }

    return res;
}

bool output(ll p)
{
    if (v2[p]) { return true; }
    v2[p] = true;

    ll ans = 0;

    for (const auto& t : G[p])
    {
        const auto q = t.first;
        const auto e = t.second;

        if (e2[e]) { continue; }
        e2[e] = true;

        const bool res = output(q);

        if (res)
        {
            cout << p + 1 << " " << q + 1 << endl;
            ++ans;
        }
        else
        {
            cout << q + 1 << " " << p + 1 << endl;
        }
    }

    return ans % 2 == 0;
}

int main()
{
    cin >> N >> M;

    rep (i, M)
    {
        ll a, b;
        cin >> a >> b;

        --a;
        --b;

        G[a].emplace_back(b, i);
        G[b].emplace_back(a, i);
    }

    bool ok = true;

    rep (i, N)
    {
        const auto res = solve(i);
        if ((res % 2) == 1) { ok = false; }

        // cout << i << ": " << res << endl;
    }

    if (ok)
    {
        rep (i, N)
        {
            output(i);
        }
    }
    else
    {
        cout << -1 << endl;
    }

    return 0;
}
