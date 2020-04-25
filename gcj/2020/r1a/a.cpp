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

const ll MAXN = 64;
string S[MAXN];
vector<ll> P[MAXN];

bool matchA(const string& a, const string& b)
{
    const ll as = a.size();
    const ll bs = b.size();

    const ll n = min(as, bs);

    rep (i, n)
    {
        if (a[i] != b[i]) { return false; }
    }

    return true;
}

bool matchB(const string& a, const string& b)
{
    const ll as = a.size();
    const ll bs = b.size();

    const ll n = min(as, bs);

    rep (i, n)
    {
        if (a[as - i - 1] != b[bs - i - 1]) { return false; }
    }

    return true;
}

int main()
{
    ll T;
    cin >>T;

    rep (t, T)
    {
        cin >> N;

        rep (i, N)
        {
            cin >> S[i];

            P[i].clear();
            rep (j, S[i].size()) { if (S[i][j] == '*') { P[i].push_back(j); } }
        }

        auto x1 = S[0].substr(0, P[0][0]);
        auto x2 = S[0].substr(P[0][0] + 1);

        bool c1 = true, c2 = true;

        REP (i, 1, N)
        {
            if (c1)
            {
                auto y1 = S[i].substr(0, P[i][0]);

                if (matchA(x1, y1))
                {
                    if (x1.size() < y1.size())
                    {
                        x1 = y1;
                    }
                }
                else
                {
                    c1 = false;
                }
            }

            if (c2)
            {
                auto y2 = S[i].substr(P[i][0] + 1);

                if (matchB(x2, y2))
                {
                    if (x2.size() < y2.size())
                    {
                        x2 = y2;
                    }
                }
                else
                {
                    c2 = false;
                }
            }
        }

        cout << "Case #" << t + 1 << ": ";

        if (c1 && c2)
        {
            cout << x1 << x2 << endl;
        }
        else
        {
            cout << "*" << endl;
        }
    }

    return 0;
}
