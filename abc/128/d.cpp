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
using namespace std;

#define REP(i,p,n) for(int i=p;i<n;++i)
#define rep(i,n) REP(i,0,n)

using ll = long long int;
using pll = pair<ll, ll>;

ll N, K;

const ll MAXN = 50;
ll D[MAXN];

ll DL[MAXN];
ll DR[MAXN];

int main()
{
    cin >> N >> K;

    rep (i, N) { cin >> D[i]; }

    // DL[i] = 0;
    // DR[i] = 0;
    // rep (i, N - 1) { DL[i + 1] = DL[i] + D[i]; }
    // rep (i, N - 1) { DR[i + 1] = DR[i] + D[N - i - 1]; }

    ll ans = 0;

    const ll NK = min(N, K);

    for (ll lnum=0;lnum<=NK;++lnum)
    for (ll rnum=0;lnum+rnum<=NK;++rnum)
    {
        const ll dnum = K - (lnum + rnum);

        ll res = 0;

        priority_queue< ll, vector<ll>, greater<ll> > Q;

        rep (i, lnum) { res += D[i]; Q.push(D[i]); }
        rep (i, rnum) { res += D[N - i - 1]; Q.push(D[N - i - 1]); }

        rep (i, dnum)
        {
            if (!Q.empty() && Q.top()<0) { res -= Q.top(); Q.pop(); }
        }

        // printf("(%lld, %lld, %lld)=%lld | %lld\n", lnum, rnum, dnum, res, ans);

        ans = max(ans, res);
    }

    cout << ans << endl;

    return 0;
}
