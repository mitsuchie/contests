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

int main()
{
    ll n;
    cin >> n;

    vector<pll> bas(n);
    for (auto& ba : bas) { cin >> ba.second >> ba.first; }

    sort(bas.begin(), bas.end());

    const auto isOK = [&]()
    {
        ll sum = 0;

        for (const auto& ba : bas)
        {
            sum += ba.second;

            if (ba.first < sum) { return false; }
        }

        return true;
    };

    const bool res = isOK();
    cout << (res ? "Yes" : "No") << endl;

    return 0;
}
