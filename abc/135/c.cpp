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
    ll N;
    cin >> N;

    vector<ll> A(N + 1);
    for (auto& a : A) { cin >> a; }

    vector<ll> B(N);
    for (auto& b : B) { cin >> b; }

    ll ans = 0;
    ll rest = 0;

    rep (i, N + 1)
    {
        const ll x = min(A[i], rest);
        ans += x;

        if (i == N) { break; }

        const ll y = min(A[i] - x, B[i]);
        ans += y;

        rest = B[i] - y;
    }

    cout << ans << endl;

    return 0;
}
