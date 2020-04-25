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

using ll = long long int;
using pll = pair<ll, ll>;

ll N;

struct R { ll to, w; };
vector< vector<R> > RS;

const ll MAXN = 100001;
int C[MAXN];

std::queue<ll> Q;

int main()
{
    cin >> N;

    RS.assign(N, vector<R>());

    ll u, v, w;
    R r;

    rep(i, N - 1)
    {
        cin >> u >> v >> w;
        --u;
        --v;

        r.to = u;
        r.w  = w;
        RS[v].push_back(r);

        r.to = v;
        r.w  = w;
        RS[u].push_back(r);
    }

    fill(C, C + N, -1);

    Q.push(0);
    C[0] = 0;

    while(!Q.empty())
    {
        const ll index = Q.front();
        Q.pop();

        for (ll i=0,n=RS[index].size();i<n;++i)
        {
            const R& r = RS[index][i];
            if (C[r.to] != -1) { continue; }

            C[r.to] = (r.w % 2) == 0 ? C[index] : 1 - C[index];

            Q.push(r.to);
        }
    }

    rep(i, N)
    {
        cout << C[i] << endl;
    }

    return 0;
}
