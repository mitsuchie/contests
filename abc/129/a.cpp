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
    ll P, Q, R;
    cin >> P >> Q >> R;

    const auto pq = P + Q;
    const auto pr = P + R;
    const auto qr = Q + R;

    const auto ans = min(pq, min(pr, qr));
    cout << ans << endl;

    return 0;
}
