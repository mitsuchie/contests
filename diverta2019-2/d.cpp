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

#define REP(i,p,n) for(int i=p;i<n;++i)
#define rep(i,n) REP(i,0,n)

using ll = long long int;
using pll = pair<ll, ll>;

ll N;

const ll MAXM = 3;
ll A[MAXM];
ll B[MAXM];

const ll MAXN = 5001 * 5001;
ll AB[MAXN];
ll BA[MAXN];

int main()
{
    cin >> N;
    rep (i, MAXM) { cin >> A[i]; }
    rep (i, MAXM) { cin >> B[i]; }

    AB[0] = N;

    for (ll w=0;w<=N;++w) if (AB[w] != 0)
    for (ll i=0;i<MAXM;++i) if (B[i] > A[i])
    {
        const auto ww = w + A[i];

        if (ww <= N) { AB[ww] = max(AB[ww], AB[w] + B[i] - A[i]); }
    }

    ll m1 = N;
    rep (i, N + 1) { m1 = max(m1, AB[i]); }

    BA[0] = m1;

    for (ll w=0;w<=m1;++w) if (BA[w] != 0)
    for (ll i=0;i<MAXM;++i) if (A[i] > B[i])
    {
        const auto ww = w + B[i];
        if (ww <= m1) { BA[ww] = max(BA[ww], BA[w] + A[i] - B[i]); }
    }

    ll m2 = m1;
    rep (i, m1 + 1) { m2 = max(m2, BA[i]); }

    cout << m2 << endl;

    return 0;
}
