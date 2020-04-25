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
    ll K, N;
    cin >> K >> N;

    vector<ll> A(N * 2);
    rep (i, N) { cin >> A[i]; A[i + N] = K + A[i]; }

    ll ans = K;

    rep (i, N)
    {
        ans = min(ans, A[i + N - 1] - A[i]);
    }

    cout << ans  << endl;

    return 0;
}
