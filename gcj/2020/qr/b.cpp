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

const ll MAXN = 128;
ll A[MAXN];
ll B[MAXN];
ll M[MAXN];

int main()
{
    ll T;
    cin >> T;

    rep (t, T)
    {
        string S;
        cin >> S;

        const ll N = S.size();
        rep (i, N) { M[i] = S[i] - '0'; }
        M[N] = 0;

        rep (i, N) { A[i] = B[i] = 0; }

        ll lhs = 0;

        while (lhs < N)
        {
            if (M[lhs] == 0) { ++lhs; continue; }

            ll res = M[lhs];

            ll rhs = lhs;
            while (M[rhs]) { res = min(res, M[rhs]); ++rhs; }

            A[lhs] += res;
            B[rhs - 1] += res;

            for (ll i=lhs;i<rhs;++i) { M[i] -= res; }
        }

        cout << "Case #" << t + 1 << ": ";

        rep (i, N)
        {
            rep (j, A[i]) { cout << "("; }
            cout << S[i];
            rep (j, B[i]) { cout << ")"; }
        }

        cout << endl;
    }

    return 0;
}
