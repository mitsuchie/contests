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

const ll MAXN = 1000001;
ll A[MAXN];
ll B[MAXN];

int main()
{
    ll N;
    cin >> N;

    string S;
    cin >> S;

    rep (i, S.size()) { A[i] = S[i] - '0'; }

    ll n = N, ans = -1, pn = 0;

    rep (j, N) if (n > 1)
    {
        ll xx = -1;
        ll nn = 0;

        auto& xs = (j % 2) == 0 ? A : B;
        auto& ys = (j % 2) == 0 ? B : A;

        rep (i, n - 1)
        {
            const auto x = abs(xs[i] - xs[i + 1]);

            if (x == xx) { continue; }
            xx = x;

            ys[nn++] = x;
            ans = x;
        }

        pn = n;
        n = nn;
    }

    cout << (pn > 2 ? 0 : ans) << endl;

    return 0;
}

