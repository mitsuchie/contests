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
    rep (k, 36)
    {
        ll ans = 0;

        ll n = k;

        for (ll i=0;i<=n;++i)
        for (ll j=0;j<=n;++j)
        {
            if (i + j > n) { continue; }

            if (i + j == (i ^ j))
            {
                // cout << i << "  " << j << endl;
                ++ans;
            }
        }

        vector<ll> bs;
        while(n > 0) { bs.push_back(n%2); n=n>>1; }
        if (bs.size() == 0) { bs.push_back(0); }
        reverse(bs.begin(), bs.end());

        for (const auto b : bs) { cout << b; }
        cout << ": ";

        cout << ans << endl;
    }

    return 0;
}
