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
vector<ll> A(N), B(N);

bool isOK()
{
    ll num = 0;

    rep (i, N)
    {
        if (A[i] <= B[i]) { ++num; }
    }


    vector<ll> AA(A);
    vector<ll> BB(B);

    sort(AA.begin(), AA.end());
    sort(BB.begin(), BB.end());

    rep (i, N)
    {
        if (A[i] > B[i]) { return false; }
    }


    return true;
}

int main()
{
    cin >> N;

    A.assign(0, N);
    B.assign(0, N);
    for (auto& a : A) { cin >> a; }
    for (auto& b : B) { cin >> b; }

    cout << (isOK() ? "Yes" : "No") << endl;

    return 0;
}
