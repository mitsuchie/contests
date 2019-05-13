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

int main()
{
    ll R, G, B, N;
    cin >> R >> G >> B >> N;

    ll ans = 0;

    for (ll r=0;r<=N;r+=R)
    {
        for (ll g=0;r+g<=N;g+=G)
        {
            const ll b = N - r - g;

            if (b == 0 || (b % B) == 0)
            {
                ++ans;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
