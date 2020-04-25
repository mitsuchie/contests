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

    ll i = 0;
    ll n = s.size();

    ll ans = 0;

    ll an = 0;

    while (i + 2 < n)
    {
        if (s[i] == 'A') { ++an; } else { an = 0; }

        if (s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'C')
        {
            ans += an;

            s[i + 0] = 'B';
            s[i + 1] = 'C';
            s[i + 2] = 'A';

            i = i + 2;
            --an;
        }
        else
        {
            ++i;
        }
    }

    cout << ans << endl;

    return 0;
}
