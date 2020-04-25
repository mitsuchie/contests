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
const ll inf = static_cast<ll>(1e10) + 7;

int main()
{
    ll X, Y, AN, BN, CN;
    cin >> X >> Y >> AN >> BN >> CN;

    vector<ll> A(AN), B(BN), C(CN);
    for (auto& x : A) { cin >> x; }
    for (auto& x : B) { cin >> x; }
    for (auto& x : C) { cin >> x; }

    sort(A.begin(), A.end(), greater<ll>());
    sort(B.begin(), B.end(), greater<ll>());
    sort(C.begin(), C.end(), greater<ll>());

    ll ai = X - 1, bi = Y - 1, ci = 0;
    ll ans = 0;

    while (ai >= 0 || bi >= 0)
    {
        const ll a = ai >= 0 ? A[ai] : inf;
        const ll b = bi >= 0 ? B[bi] : inf;
        const ll c = ci < CN ? C[ci] : -1;

        if (a < b)
        {
            if (a < c)
            {
                ans += c;
                ++ci;
            }
            else
            {
                ans += a;
            }

            --ai;
        }
        else
        {
            if (b < c)
            {
                ans += c;
                ++ci;
            }
            else
            {
                ans += b;
            }

            --bi;
        }
    }

    cout << ans << endl;

    return 0;
}
