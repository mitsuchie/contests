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

bool isOK(const string& s)
{
    const ll n = s.size();

    rep (i, n)
    {
        if (s[i] != s[n - i - 1]) { return false; }
    }

    const ll n2 = (n - 1) / 2;

    rep (i, n2)
    {
        if (s[i] != s[n2 - i - 1]) { return false; }
    }

    const ll n3 = (n + 3) / 2;

    rep (i, n - n3)
    {
        if (s[i + n3 - 1] != s[n - i - 1]) { return false; }
    }

    return true;
}

int main()
{
    string s;
    cin >> s;

    cout << (isOK(s) ? "Yes" : "No") << endl;

    return 0;
}
