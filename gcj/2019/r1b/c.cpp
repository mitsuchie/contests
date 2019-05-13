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

const int MAXN = 128;
ll C[MAXN];
ll D[MAXN];

ll CM[MAXN];
ll DM[MAXN];

int main()
{
    int T;
    cin >> T;

    rep(t, T)
    {
        ll ans = 0;

        ll N, K;
        cin >> N >> K;

        if (N >= MAXN)
        {
            printf("Case #%d: %lld\n", t + 1, ans);
            continue;
        }

        rep (i, N) { cin >> C[i]; }
        rep (i, N) { cin >> D[i]; }

        for (int i=0;i<N;++i)
        for (int j=i;j<N;++j)
        {
            int lhs = 0;
            int rhs = 0;

            for (int k=i;k<=j;++k)
            {
                lhs = max<ll>(lhs, C[k]);
                rhs = max<ll>(rhs, D[k]);
            }

            if (abs(lhs - rhs) <= K) { ++ans; }
        }

        printf("Case #%d: %lld\n", t + 1, ans);
    }

    return 0;
}
