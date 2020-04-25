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

const ll MAXN = 100002;
ll dp[MAXN];

const ll mod = 1000000007;

int main()
{
    string s;
    cin >> s;

    dp[0] = 0;
    dp[1] = 2;

    rep (i, MAXN -1)
    {
        dp[i + 1] = dp[i] * 2;
        dp[i + 1] %= mod;
    }

    return 0;
}
