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
    int N;
    cin >> N;

    vector<int> ws(N);
    rep (i, N) { cin >> ws[i]; }

    int sum = 0;
    rep (i, N) { sum += ws[i]; }

    int lhs = 0;
    int rhs = sum;

    int ans = sum;

    rep (i, N)
    {
        lhs += ws[i];
        rhs -= ws[i];

        ans = min(ans, abs(rhs - lhs));
    }

    cout << ans << endl;

    return 0;
}
