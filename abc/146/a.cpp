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

    if (s == "SUN") { cout << 7 << endl; }
    if (s == "MON") { cout << 6 << endl; }
    if (s == "TUE") { cout << 5 << endl; }
    if (s == "WED") { cout << 4 << endl; }
    if (s == "THU") { cout << 3 << endl; }
    if (s == "FRI") { cout << 2 << endl; }
    if (s == "SAT") { cout << 1 << endl; }

    return 0;
}
