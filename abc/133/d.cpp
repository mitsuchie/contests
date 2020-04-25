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

    vector<ll> A(N);
    rep (i, N) { cin >> A[i]; }

    vector<ll> B(N + 1);
    fill(B.begin(), B.end(), 0);

    rep (i, N) { B[N] += (i % 2 ? -1 : 1) * A[i]; }

    for (ll i=N-1;i>=0;--i)
    {
        B[i] = (A[i] * 2) - B[i + 1];
    }

    rep (i, N) { cout << B[i] << " "; }
    cout << endl;

    return 0;
}
