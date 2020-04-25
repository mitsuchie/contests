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
    ll H, W;
    cin >> H >> W;

    if (W == 1 || H == 1)
    {
        cout << 1 << endl;
        return 0;
    }

    const ll x = (H * W) / 2;
    const ll y = (H % 2 == 0) || (W % 2 == 0) ? 0 : 1;

    const ll ans = x + y;
    cout << ans << endl;

    return 0;
}
