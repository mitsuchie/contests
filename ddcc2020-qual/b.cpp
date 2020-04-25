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


    ll sum = 0;
    for (const auto& a : A) { sum += a; }


    ll lhs = 0, rhs = sum, minDistance = sum;

    for (const auto& a : A)
    {
        lhs += a;
        rhs -= a;

        const auto& distance = abs(rhs - lhs);
        minDistance = min(distance, minDistance);
    }

    cout << minDistance << endl;

    return 0;
}
