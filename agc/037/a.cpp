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

string S;

ll N;

ll solve(ll lhs, ll rhs, ll k, const string* t)
{
    if (rhs == N - 1)
    {
        const auto s = S.substr(lhs, rhs - lhs + 1);
        if (t && *t == s) { return 0LL; }

        return k + 1;
    }

    ll ans = 0;

    // 結合先延ばしパターン
    {
        const ll res = solve(lhs, rhs + 1, k, t);
        ans = max(ans, res);
    }

    // 早速結合パターン
    {
        const auto s = S.substr(lhs, rhs - lhs + 1);

        if (t == nullptr || s != *t)
        {
            const ll res = solve(rhs + 1, rhs + 1, k + 1, &s);
            ans = max(ans, res);
        }
    }

    return ans;
}

int main()
{
    cin >> S;
    N = static_cast<ll>(S.size());

    const ll ans = solve(0, 0, 0, nullptr);
    cout << ans << endl;

    return 0;
}
