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
string S;

bool solve(ll n, ll p)
{
    if (n == N)
    {
        cout << S << endl;
        return true;
    }

    rep (i, n + p)
    {
        S[n] = ('a' + i);

        const bool res = solve(n + 1, (i == n ? 1 : 0));
        if (!res) { return false; }
    }

    return true;
}


int main()
{
    cin >> N;
    rep (i, N) { S += 'a'; }

    solve(0, 1);

    return 0;
}
