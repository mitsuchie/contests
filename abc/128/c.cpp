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

ll N, M;

const int MAXN = 10;
vector<ll> S[MAXN];
ll P[MAXN];

ll solve(ll depth)
{
    if (depth == N) { return 1; }



}

int main()
{
    cin >> N >> M;

    rep(i, M)
    {
        ll k;
        cin >> k;

        S[i].assign(k, 0);

        rep(j, k) { cin >> S[i][j]; --S[i][j]; }
    }

    rep(i, M)
    {
        cin >> P[i];
    }

    ll ans = 0;

    for (ll i=0,n=(1<<N);i<n;++i)
    {
        bool ok = true;

        for (ll j=0;j<M;++j)
        {
            ll num = 0;

            for (ll k=0;k<S[j].size();++k)
            {
                if (i & (1 << S[j][k])) { ++num; }
            }

            if ((num & 1) != P[j]) { ok = false; }
        }

        if (ok) { ++ans; }
    }

    cout << ans << endl;

    return 0;
}
