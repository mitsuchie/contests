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

int main()
{
    ll N;
    cin >> N;

    string S;
    cin >> S;

    bool ok = true;

    for (ll i=0;i<N;++i)
    {
        const char c = (i % 2) ? 'W' : 'B';
        ok &= S[i] == c && S[2 * N - i - 1] == c;
    }



    return 0;
}
