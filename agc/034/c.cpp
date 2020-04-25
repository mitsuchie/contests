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

ll N, X;

struct Test
{
    ll b, l, u;
    ll bl;

    bool operator<(const Test& t)
    {
        if (u == t.u) { return b < t.b; }

        return u >= t.u;
    }
};

int main()
{
    cin >> N >> X;

    vector<Test> ts(N);

    for (auto& t : ts) { cin >> t.b >> t.l >> t.u; }
    for (auto& t : ts) { t.bl = t.b * t.l; }

    ll s = 0;
    for (const auto& t : ts) { s += t.bl; }

    sort(ts.begin(), ts.end());

    ll ans = 0;
    ll ccc = 0;

    for (ll i=0;i<N;++i)
    {
        const auto& t = ts[i];
        cout << i << ": b=" << t.b << " l=" << t.l << " u=" << t.u << endl;

        const auto ss = s - t.bl + t.b * t.u;
        s = ss;

        if (s <= ccc + X * t.u)
        {
            ans += (s - ccc) / t.u;

            break;
        }

        ccc += X * t.u;
        ans += X;
    }

    cout << ans << endl;

    return 0;
}
