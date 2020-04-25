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

int main()
{
    ll r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;

    ll ans = 0;
    ll sum = c2 - c1 + 1;

    for (ll r=0;r<=r2;++r)
    {
        if (r1 <= r)
        {
            ans += sum;
        }

        sum += ((c2 - c1 + 1) * (c1 + c2)) >> 1;
        cout << "ans=" << ans << ", sum=" << sum << endl;
    }

    cout << ans << endl;

    return 0;
}
