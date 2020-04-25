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

ll N, Q;

int main()
{
    cin >> N >> Q;

    vector<pll> ss(N);
    vector<pll> ts(N);

    rep (i, N)
    {
        ll s, t, x;

        cin >> s >> t >> x;
        s -= x;
        t -= x;

        ss[i] = pll(s, x);
        ts[i] = pll(t, x);

    }

    sort(ss.begin(), ss.end());
    sort(ts.begin(), ts.end());

    multiset<ll> xs;

    ll si = 0;
    ll ti = 0;

    rep (i, Q)
    {
        ll d;
        cin >> d;

        while (si < ss.size() && ss[si].first <= d)
        {
            xs.insert(ss[si].second);
            ++si;
        }

        while (ti < ts.size() && ts[ti].first <= d)
        {
            xs.erase(xs.lower_bound(ts[ti].second));
            ++ti;
        }

        cout << (xs.size() == 0 ? -1 : (*xs.begin())) << endl;
    }

    return 0;
}
