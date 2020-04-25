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

#define REP(i,p,n) for(int i=p;i<n;++i)
#define rep(i,n) REP(i,0,n)

using ll = long long int;
using pll = pair<ll, ll>;

int main()
{
    ll N, X;
    cin >> N >> X;

    vector<ll> L(N);
    for (auto& l : L) { cin >> l; }

    ll ans = 1;

    ll D = 0;

    for (const auto& l : L)
    {
        D += l;

        if (D <= X) { ++ans; }
    }

    cout << ans << endl;


    return 0;
}
