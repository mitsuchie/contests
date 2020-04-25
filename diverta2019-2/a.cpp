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
    int N, K;
    cin >> N >> K;

    if (K == 1)
    {
        cout << 0 << endl;
    }
    else
    {
        const ll lhs = 1;
        const ll rhs = N - K + 1;

        cout << (rhs - lhs) <<  endl;
    }

    return 0;
}
