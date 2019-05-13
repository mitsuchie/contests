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

int main()
{
    ll N;
    cin >> N;

    ll ans = 0;

    vector<ll> divisors;

    for (ll i=1;i*i<=N;++i)
    {
        if ((N % i) == 0)
        {
            divisors.push_back(i);

            const ll j = N / i;
            if (i != j) { divisors.push_back(j); }
        }
    }

    for (const auto i : divisors)
    {
        const ll num = i - 1;

        if (num >= 1 && N / num == N % num)
        {
            ans += num;
        }
    }

    cout << ans << endl;

    return 0;
}
