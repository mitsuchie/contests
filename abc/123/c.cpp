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

const ll MAXT = 5;
ll T[MAXT];

ll N;

int main()
{
    cin >> N;
    rep(i, MAXT) { cin >> T[i]; }

    ll t = T[0];
    rep(i, MAXT) { t = std::min<ll>(t, T[i]); }

    const ll t1 = N / t;
    const ll t2 = (N % t) == 0 ? 0 : 1;

    cout << 4 + (t1 + t2) << endl;

    return 0;
}
