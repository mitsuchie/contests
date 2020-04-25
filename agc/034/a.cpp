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

ll N, A, B, C, D;
string S;

bool isOK(ll p, ll q)
{
    for (ll i=p;i<=q-1;++i)
    {
        if (S[i] == '#' && S[i + 1] == '#') { return false; }
    }

    return true;
}

int main()
{
    cin >> N >> A >> B >> C >> D;
    --A;
    --B;
    --C;
    --D;

    cin >> S;

    bool ok = true;

    if (D < C)
    {
        ok = false;

        for (ll i=B;i<=D;++i)
        {
            if (i - 1 < 0 || N <= i + 1) { continue; }

            if (S[i - 1] != '#' && S[i] != '#' && S[i + 1] != '#')
            {
                ok = true;
            }
        }
    }

    ok = ok && isOK(A, C) && isOK(B, D);

    cout << (ok ? "Yes" : "No") << endl;

    return 0;
}
