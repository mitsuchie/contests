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
    ll N, K;
    cin >> N >> K;

    vector<ll> A(N);
    for (auto& a : A) { cin >> a; }

    ll ans = 0;

    ll l = 0, r = 0;
    ll sum = 0;

    while (l < N)
    {
        if (r < N && sum < K)
        {
            sum += A[r];
            ++r;
        }
        else
        {
            sum -= A[l];
            ++l;
        }

        if (sum >= K) { ans += N - r + 1; }
    }

    cout << ans << endl;

    return 0;
}
