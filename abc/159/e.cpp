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

ll H, W, K;

const ll MAXH = 11;
string S[MAXH];

ll N[MAXH];
ll M[MAXH];

ll solve(ll b)
{
    rep (i, H) { N[i] = 0; }

    ll res = 0;
    rep (i, H) { res += (b>>i)&1; }

    for (ll x=0;x<W;++x)
    {
        rep (i, H) { M[i] = 0; }

        ll ni = 0;

        for (ll y=0;y<H;++y)
        {
            // ホワイトチョコが見つかった
            if (S[y][x] == '1') { ++M[ni]; }

            // 失敗させる
            if (M[ni] > K) { return H * W + 1; }

            // 横の区切りが見つかった
            if ((b>>y)&1) { ++ni; }
        }

        bool isOver = false;

        rep (j, ni + 1)
        {
            N[j] += M[j];
            if (N[j] > K) { isOver = true; }
        }

        if (isOver)
        {
            ++res;
            rep (j, ni + 1) { N[j] = M[j]; }
        }
    }

    return res;
}

int main()
{
    cin >> H >> W >> K;
    rep (i, H) { cin >> S[i]; }

    ll ans = H * W + 1;

    for (ll i=0,n=(1<<(H-1));i<n;++i)
    {
        const ll res = solve(i);
        ans = min(ans, res);
    }

    cout << ans << endl;

    return 0;
}
