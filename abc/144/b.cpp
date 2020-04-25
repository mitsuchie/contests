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

bool isOK(ll n)
{
    for (ll a=1;a<=9;++a)
    for (ll b=1;b<=9;++b)
    {
        if (a * b == n)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    ll N;
    cin >> N;

    const bool ok = isOK(N);
    cout << (ok ? "Yes" : "No") << endl;

    return 0;
}
