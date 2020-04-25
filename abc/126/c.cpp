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

const int MAXN = 100000;
ll C[MAXN];

int main()
{
    ll N, K;
    cin >> N >> K;

    rep(i, N)
    {
        C[i] = 1;

        ll p = i + 1;
        while (p < K) { C[i] *= 2; p *= 2; }
    }

    double ans = 0.0;

    rep(i, N)
    {
        ans += 1.0 / (static_cast<double>(C[i] * N));
    }

    printf("%0.09lf\n", ans);

    return 0;
}
