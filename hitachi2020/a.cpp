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
    string s;
    cin >> s;

    bool res = (s.size() % 2) == 0;

    rep (i, s.size() / 2)
    {
        res &= s[i * 2] == 'h' && s[i * 2 + 1] == 'i';
    }

    cout << (res ? "Yes" : "No") << endl;

    return 0;
}
