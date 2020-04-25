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
    string s;
    cin >> s;

    int ss[24] = { 0 };

    for (const auto& c : s) { ++ss[c - 'A']; }

    bool ok = true;
    int count = 0;

    rep (i, 24)
    {
        if (!(ss[i] == 0 || ss[i] == 2)) { ok = false; }
        if (ss[i] == 2) { ++count; }
    }

    if (ok && count == 2)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}
