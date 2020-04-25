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

ll N, M;

int main()
{
    cin >> N >> M;

    ll lin = 0, rin = 0;
    ll lhs = 0, rhs = 0;

    rep(i, M)
    {
        cin >> lin >> rin;

        if (i == 0)
        {
            lhs = lin;
            rhs = rin;
        }

        lhs = max(lhs, lin);
        rhs = min(rhs, rin);
    }

    cout << max<ll>(0, rhs - lhs + 1) << endl;

    return 0;
}
