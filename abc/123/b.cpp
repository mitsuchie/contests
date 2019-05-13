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

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vint;
typedef vector<pii> vpii;
typedef vector<vint> det1;
typedef vector<vpii> det2;

const int N = 5;
const int INF = 100000;

int times[N];
bool done[N];

int solve(int d, int t)
{
    if (d == N) { return t; }

    int ans = -1;

    rep(i, N)
    {
        if (done[i]) { continue; }

        done[i] = true;

        const int tt = (t % 10) == 0 ? t : ((t / 10) + 1) * 10;
        const int res = solve(d + 1, tt + times[i]);

        if (ans < 0 || res < ans) { ans = res; }

        done[i] = false;
    }

    return ans == -1 ? INF : ans;
}

int main()
{
    rep(i, N) { cin >> times[i]; }

    cout << solve(0, 0) << endl;

    return 0;
}
