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
using namespace std;

#define REP(i,p,n) for(int i=p;i<n;++i)
#define rep(i,n) REP(i,0,n)

using ll = long long int;
using pll = pair<ll, ll>;

int N;

int main()
{
    cin >> N;

    vector<string> S(N);
    rep (i, N) { cin >> S[i]; }

    ll ans = 0;

    ll ba = 0;
    ll b = 0;
    ll a = 0;

    rep (i, N)
    {
        const auto& s = S[i];

        for (ll j=0,n=s.size();j+1<n;++j)
        {
            if (s[j] == 'A' && s[j + 1] == 'B') { ++ans; }
        }

        const char head = s[0];
        const char last = s[s.size() - 1];

        if (head == 'B' && last == 'A') { ++ba; }
        else if (last == 'A') { ++a; }
        else if (head == 'B') { ++b; }
    }

    bool isOdd = false;

    if (a)
    {
        isOdd = true;
        --a;
    }

    while (ba)
    {
        if (isOdd) { ++ans; }
        --ba;
        isOdd = true;
    }

    while(a || b)
    {
        if (isOdd)
        {
            if (!b) { break; }

            --b;
            ++ans;
        }
        else
        {
            if (!a) { break; }

            --a;
        }

        isOdd = !isOdd;
    }

    cout << ans << endl;

    return 0;
}
