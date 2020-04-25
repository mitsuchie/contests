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

int main()
{
    ll N;
    cin >> N;

    if (N == 1)
    {
        cout << 1 << endl;

        return 0;
    }

    vector<pll> ps(N);
    for (auto& p : ps) { cin >> p.first >> p.second; }

    ll ans = 1000;

    for (ll i=0;i<N;++i)
    for (ll j=i+1;j<N;++j)
    {
        const auto& pi = ps[i];
        const auto& pj = ps[j];

        const auto dx = pi.first  - pj.first;
        const auto dy = pi.second - pj.second;

        ll n1 = 0, n2 = 0;

        for (ll s=0;s<N;++s)
        for (ll t=0;t<N;++t)
        {
            const auto& p1 = ps[s];
            const auto& p2 = ps[t];

            const auto x1 = p1.first  - p2.first;
            const auto y1 = p1.second - p2.second;

            const auto x2 = -(p1.first  - p2.first);
            const auto y2 = -(p1.second - p2.second);

            if (x1 == dx && y1 == dy) { ++n1; }
            if (x2 == dx && y2 == dy) { ++n2; }
        }

        ans = min(ans, N - n1);
        ans = min(ans, N - n2);
    }

    cout << ans << endl;

    return 0;
}
