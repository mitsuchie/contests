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

#define REP(i,p,n) for(ll i=p;i<n;++i)
#define rep(i,n) REP(i,0,n)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vint;
typedef vector<pii> vpii;
typedef vector<vint> det1;
typedef vector<vpii> det2;

ll R, B, C;

const ll MAXC = 36;
ll M[MAXC], S[MAXC], P[MAXC];

ll INF = 1000000000000000000LL;
// ll cache[MAXC][MAXC][MAXC];

ll calc(ll depth, ll ci, ll bits)
{
    if (bits == 0)  { return 0; }
    if (depth >= R || ci >= C) { return INF; }

    // if (cache[depth][ci][bits] != -1) { return cache[depth][ci][bits]; }

    ll res = INF;

    for(ll c=ci;c<C;++c)
    for(ll b=1;b<=bits&&b<=M[c];++b)
    {
        ll rest_bits = bits - b;
        ll next_cidx = c + 1;

        ll mycost = S[c] * b + P[c];

        ll cost = max(mycost, calc(depth + 1, next_cidx, rest_bits));
        // cout<<"depth="<<depth<<", c="<<c<<", b="<<b<<", my="<<mycost<<", cost="<<cost<<endl;

        res = min(res, cost);
    }

    return res;
    // return cache[depth][ci][bits] = res;
}

ll solve()
{
    cin>>R>>B>>C;

    rep(i, C)
    {
        cin>>M[i]>>S[i]>>P[i];
    }

    /*
    rep(i, MAXC)
    rep(j, MAXC)
    rep(k, MAXC)
    {
        cache[i][j][k] = -1;
    }
    */

    ll res = calc(0, 0, B);
    return res == INF ? 0 : res;
}

int main()
{
    int t;
    cin>>t;

    rep(i, t)
    {
        ll res = solve();
        cout<<"Case #"<<(i+1)<<": "<<res<<endl;
    }

    return 0;
}
