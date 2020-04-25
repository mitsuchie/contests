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
// ll B[MAXM];
// ll C[MAXM];

pair<ll, ll> CB[MAXM];
 
 
int main()
{
    cin >> N >> M;
 
    rep (i, N) { cin >> A[i]; }
    rep (i, M) { cin >> CB[i].second >> CB[i].first; }

    sort(CB, CB + M);
    reverse(CB, CB + M);
 
    priority_queue<ll, vector<ll>, greater<ll> > Q;
    rep (i, N) { Q.push(A[i]); }
 
    rep (i, M)
    {
        rep (j, CB[i].second)
        {
            const ll val = Q.top();
            if (val >= CB[i].first) { break; }
 
            Q.pop();
            Q.push(CB[i].first);
        }
    }
 
    ll ans = 0;
 
    while (!Q.empty())
    {
        ans += Q.top();
        Q.pop();
    }
 
    cout << ans << endl;
 
    return 0;
}
