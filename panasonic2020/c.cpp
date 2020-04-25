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
    ll a, b, c;
    cin >> a >> b >> c;

    const ll lhs = 4 * a * b;

    const ll x = c - a - b;
    const ll rhs = x * x;

    cout << (x >= 0 && lhs < rhs ? "Yes" : "No") << endl;

    return 0;
}
