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

using ll = long long int;

vector<ll> P;

const ll MAXN = 10002;
bool isNotPrime[MAXN];


void preparePrime()
{
    isNotPrime[0] = true;
    isNotPrime[1] = true;

    for (ll i=2;i*i<=MAXN;++i)
    {
        if (!isNotPrime[i])
        {
            for (ll j=i*2;j<MAXN;j+=i) { isNotPrime[j] = true; }
        }
    }
}

void calcPrime(ll n)
{
    P.clear();

    const ll nn = std::min<ll>(n + 1, MAXN);
    rep(i, nn) { if (!isNotPrime[i]) { P.push_back(i); } }
}

int main()
{
    preparePrime();

    int T;
    cin >> T;

    rep (i, T)
    {
        ll N, L;
        cin >> N >> L;

        calcPrime(N);

        rep(i, L)
        {
            ll m;
            cin >> m;

            set<ll> u;
            vector<ll> s;

            for (ll j=0;j<P.size();++j)
            for (ll k=j+1;k<P.size();++k)
            {
                if (P[j] * P[k] == m)
                {
                    u.insert(P[j]);
                    u.insert(P[k]);

                    s.push_back(j);
                }
            }

            vector<ll> q;

            for (const auto qq : u)
            {
                q.push_back(qq);
            }

            rep(j, s.size())
            {
                cout << ('A' + q.find(s[j]));
            }

            cout << endl;
        }
    }

    return 0;
}
