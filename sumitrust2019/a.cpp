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
    ll m1, d1;
    ll m2, d2;

    cin >> m1 >> d1;
    cin >> m2 >> d2;

    const bool ok = m1 != m2 && d2 == 1;
    cout << (ok ? 1 : 0) << endl;

    return 0;
}
