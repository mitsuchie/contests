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
    ll X, Y;
    cin >> X >> Y;

    const ll x = X == 1 ? 300000 : X == 2 ? 200000 : X == 3 ? 100000 : 0;
    const ll y = Y == 1 ? 300000 : Y == 2 ? 200000 : Y == 3 ? 100000 : 0;
    const ll z = X == 1 && Y == 1 ? 400000 : 0;

    const ll ans = x + y + z;
    cout << ans << endl;

    return 0;
}
