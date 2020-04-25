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

ll N;

const ll MAXN = 99;
char C[MAXN * 2 + 1];

int main()
{
    cin >> N;

    string ss;

    rep (i, N + 1)
    {
        cout << "? ";
        rep (j, N) { cout << j + i + 1 << " "; }
        cout << endl;

        string s;
        cin >> s;

        if (ss.size() != 0 && ss != s)
        {
            C[i] = (s == "Red") ? 'R' : 'B';
        }
        else
        {
            C[i] = '?';
        }
    }

    cout << "! " << C << endl;

    return 0;
}
