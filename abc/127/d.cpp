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

ll N, M;

const int MAXN = 100000;
const int MAXM = MAXN;
ll A[MAXN];
ll D[MAXN];

pair<ll, ll> CB[MAXN];

int main()
{
    cin >> N >> M;

    rep (i, N) { cin >> A[i]; }

    rep (i, M) { cin >> CB[i].second >> CB[i].first; }

    sort(CB, CB + M);
    revese(CB, CB + M);

    /*
    priority_queue<ll, vector<ll>, greater<ll> > Q;

    ll len = 0;

    rep (i, M)
    {
        rep(i, B[i])
        {
            if (B[i] <= Q.top()) { break; }

            Q.push(C[i]);
            ++len;

            Q.pop(C[i]);
        }
    }

    rep (i, N) { cout << A[i] << " "; } cout << endl;
    */

    return 0;
}
