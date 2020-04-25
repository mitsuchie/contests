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
    ll ans = 0;

    priority_queue<pll> Q;
    Q.push(pll(0, 0));

    while (true)
    {
        const auto top = Q.top();

        const auto time = top.first;
        const auto used = top.second;

        Q.pop();

    }



    return 0;
}
