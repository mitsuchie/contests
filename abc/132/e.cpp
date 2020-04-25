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

const ll MAXN = 100000;
const ll INF = 10000000;
vector<ll> G[MAXN];

bool visited1[MAXN];
bool visited2[MAXN];

int main()
{
    ll n, m;
    cin >> n >> m;

    rep (i, m)
    {
        ll u, v;
        cin >> u >> v;

        --u;
        --v;

        G[u].push_back(v);
    }

    ll s, t;
    cin >> s >> t;
    --s;
    --t;

    vector<ll> costs(n);
    fill(costs.begin(), costs.end(), INF);

    queue<ll> Q;
    Q.push(s);

    costs[s] = 0;

    while (!Q.empty())
    {
        const auto u = Q.front();
        Q.pop();

        for (const auto& v1 : G[u])
        {
            if (visited1[v1]) { continue; }
            visited1[v1] = true;

            for (const auto& v2 : G[v1])
            {
                if (visited2[v2]) { continue; }
                visited2[v2] = true;

                for (const auto& v3 : G[v2])
                {
                    if (costs[v3] != INF) { continue; }

                    costs[v3] = costs[u] + 1;
                    Q.push(v3);
                }
            }
        }
    }

    if (costs[t] != INF)
    {
        cout << costs[t] << endl;
    }
    else
    {
        cout << -1 << endl;
    }

    return 0;
}
