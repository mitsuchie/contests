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
    ll A, B;
    cin >> A >> B;

    const ll ans = (A + B) / 2;

    if (abs(A - ans) - abs(B - ans) == 0)
    {
        cout << ans << endl;
    }
    else
    {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}
