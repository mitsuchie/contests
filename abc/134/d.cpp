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
    ll N;
    cin >> N;

    vector<ll> A(N);
    for (auto& a : A) { cin >> a; }

    vector<ll> B(N);
    fill(B.begin(), B.end(), 0);

    ll M = 0;

    for (ll i=N;i>=1;--i)
    {
        for (ll j=i;j<=N;j+=i) { B[i - 1] += B[j - 1]; }
        B[i - 1] += A[i - 1];

        B[i - 1] %= 2;
        M += B[i - 1];
    }

    cout << M << endl;

    if (M != 0)
    {
        for (ll i=0;i<N;++i)
        {
            if (B[i]) { cout << i + 1 << " "; }
        }

        cout << endl;
    }

    return 0;
}
