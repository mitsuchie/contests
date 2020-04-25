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
    string s;
    cin >> s;

    int n = 0;
    rep (i, s.size()) { if (s[i] == 'o') { ++n; } }

    cout << ((15 - s.size() + n) >= 8 ? "YES" : "NO") << endl;

    return 0;
}
