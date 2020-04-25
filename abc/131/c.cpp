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

ll gcd(ll a, ll b)
{
    if (a == 0) { return b; }

    return gcd(b % a, a);
}

ll lcm(ll a, ll b)
{
    return a * b / gcd(a, b);
}

int main()
{
    ll a, b, c, d;
    cin >> a >> b >> c >> d;


    const ll sum = b - a + 1;

    const ll ac = (a - 1) / c;
    const ll bc = b / c;
    const ll cc = bc - ac;

    const ll ad = (a - 1) / d;
    const ll bd = b / d;
    const ll dd = bd - ad;

    const ll lcm_cd = lcm(min(c, d), max(c, d));

    const ll ax = (a - 1) / lcm_cd;
    const ll bx = b / lcm_cd;
    const ll xx = bx - ax;

    cout << (sum - cc - dd + xx) << endl;

    return 0;
}
