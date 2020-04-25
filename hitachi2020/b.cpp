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

ll AN, BN, M;

int main()
{
    cin >> AN >> BN >> M;

    vector<ll> A(AN);
    vector<ll> B(BN);
    for (auto& a : A) { cin >> a; }
    for (auto& b : B) { cin >> b; }

    const auto ma = min_element(A.begin(), A.end());
    const auto mb = min_element(B.begin(), B.end());

    ll ans = *ma + *mb;

    rep (i, M)
    {
        ll x, y, c;
        cin >> x >> y >> c;
        --x;
        --y;

        const ll res = A[x] + B[y] - c;
        ans = min(res, ans);
    }

    cout << ans << endl;

    return 0;
}
