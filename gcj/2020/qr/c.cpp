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

ll N;

const ll MAXN = 1024;
pair<pll, ll> M[MAXN];
char S[MAXN];

bool solve(int index, int at, int bt)
{
    // 最後まで行けたら成功
    if (index == N)
    {
        return true;
    }

    const auto s = M[index].first.second;
    const auto t = M[index].first.first;
    const auto k = M[index].second;

    // Aに割り振る
    if (at <= s)
    {
        S[k] = 'C';

        const bool res = solve(index + 1, t, bt);
        if (res) { return true; }
    }

    // Bに割り振る
    if (bt <= s)
    {
        S[k] = 'J';

        const bool res = solve(index + 1, at, t);
        if (res) { return true; }
    }

    // 失敗
    return false;
}


int main()
{
    ll T;
    cin >> T;

    rep (t, T)
    {
        cin >> N;
        S[N] = 0;

        rep (i, N)
        {
            cin >> M[i].first.second >> M[i].first.first;
            M[i].second = i;
        }

        sort(M, M + N);

        const bool res = solve(0, 0, 0);

        cout << "Case #" << t + 1 << ": " << (res ? S : "IMPOSSIBLE") << endl;
    }

    return 0;
}
