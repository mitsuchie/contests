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

    vector<ll> A(N);
    for (auto& a : A) { cin >> a; }

    vector<ll> B(N);
    fill(B.begin(), B.end(), 0);

    ll ans = 0;

    for (ll i=0;i<N;++i) if (!B[i])
    {
        ll val = -1;

        ++ans;

        for (ll j=i;j<N;++j)
        {
            if (A[j] < val) { B[j] = 1; val = A[j]; }
        }
    }

    cout << ans << endl;

    return 0;
}
