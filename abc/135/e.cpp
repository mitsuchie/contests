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
    ll K;
    cin >> K;

    ll X, Y;
    cin >> X >> Y;

    if (abs(X) + abs(Y) == K)
    {
        cout << 1 << endl;
        cout << X << " " << Y << endl;
    }
    else
    {
        const ll xm = K - (abs(X) % K);

        const ll y1 = Y + xm;
        const ll y2 = Y - xm;
        const ll yy = abs(y1) % 2 == 0 ? y1 : y2;

        cout << y1 << " " << y2 << endl;

        if ((abs(y1) % 2 == 0) || (abs(y2) % 2 == 0))
        {
            const ll n = (abs(X) / K) + (K - (abs(X) % K));
            cout << n << endl;

            ll x = 0, y = 0;

            while (x != X)
            {
                const ll dx = min(K, (x < X  ? X  - x : x - X));
                const ll dy = min(K - dx, (y < yy ? yy - y : y - yy));

                x += (x < X  ? 1: -1) * dx;
                y += (y < yy ? 1: -1) * dy;

                cout << x << " " << y << endl;
            }

            while (y != Y)
            {
                const ll dd = abs(Y - y);

                ll dy = 1;

                while (dy < dd && dy > K)
                {
                    dy = dy << 1;
                }

                y += (y < Y ? 1 : -1) * dy;
                cout << x + (K - dy) << " " << y << endl;

                y += (y < Y ? 1 : -1) * dy;
                cout << x << " " << y << endl;
            }
        }
        else
        {
            cout << -1 << endl;
        }
    }

    return 0;
}
