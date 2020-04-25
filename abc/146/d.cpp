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

const ll MAXN = 100000;
ll N;
ll M;

struct Edge
{
    Edge() {}

    ll src = 0;
    ll dst = 0;
    ll color = -1;
};

vector<Edge> E;

vector< vector<Edge*> > G;
// vector<ll> C;
// vector<ll> K;

void solve(ll src)
{
    const auto calcUsed = [](ll index)
    {
        ll used = 0;

        for (const auto& edge : G[index])
        {
            if (edge->color == -1) { continue; }

            used |= (1 << edge->color);
        }

        return used;
    };

    for (const auto& edge : G[src])
    {
        if (edge->color != -1) { continue; }

        const ll used = calcUsed(src);

        rep (i, 32)
        {
            if ((used >> i) & 1) { continue; }

            edge->color = i;
            M = max(M, i);

            solve(i);

            break;
        }
    }
}

int main()
{
    cin >> N;
    E.assign(N, Edge());

    rep (i, N)
    {
        ll a, b;
        cin >> a >> b;

        --a;
        --b;

        E[i].src = a;
        E[i].dst = b;

        G[a].push_back(&E[i]);
        G[b].push_back(&E[i]);
    }

    rep (i, N)
    {
        solve(i);
    }

    cout << "M=" << M << endl;

    for (const auto& edge : E)
    {
        cout << (edge.color + 1) << endl;
    }

    return 0;
}
