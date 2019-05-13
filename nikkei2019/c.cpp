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
typedef pair<ll,ll> pii;
typedef vector<ll> vint;
typedef vector<pii> vpii;
typedef vector<vint> det1;
typedef vector<vpii> det2;

const int MAXN = 100000;

int N;
int A[MAXN], B[MAXN];

int main()
{
    cin >> N;
    rep(i, N) { cin >> A[i] >> B[i]; }

    vector<pii> C(N);

    rep(i, N) { C[i].first = A[i] + B[i]; C[i].second = i; }

    sort(C.begin(), C.end(), greater<pii>());

    ll ans = 0;

    rep(i, N)
    {
        ans += (i % 2) == 0 ? A[C[i].second] : -B[C[i].second];
    }

    cout << ans << endl;

    return 0;
}
