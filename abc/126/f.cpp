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
    ll M, K;
    cin >> M >> K;

    if (K == 0)
    {
        ll index = 0;
        ll n = 1 << (M + 1);

        rep(i, n)
        {
            cout << index << (i == n - 1 ? "" : " ");
            if ((i % 2) == 1) { ++index; }
        }

        cout << endl;
    }
    else
    {
        cout << -1 << endl;
    }

    return 0;
}
