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

    vector<ll> A(N), B(N);
    rep (i, N) { cin >> A[i]; B[i] = A[i]; }

    sort(B.begin(), B.end());

    rep (i, N)
    {
        const bool isMax = A[i] == B[N - 1];
        cout << (isMax ? B[N - 2] : B[N - 1]) << endl;
    }

    return 0;
}
