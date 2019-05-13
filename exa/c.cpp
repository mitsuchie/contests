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

const int MAXT = 256;
int P[MAXT], MAXL[MAXT], MAXR[MAXT];

int N, Q;

int main()
{
    cin >> N >> Q;

    string s;
    cin >> s;

    char t, d;

    rep(i, Q)
    {
        cin >> t >> d;

        const int index = t - 'A';
        const int lr = (d == 'L' ? -1 : 1);

        P[index] += lr;
        MAXL[index] = min(MAXL[index], P[index]);
        MAXR[index] = max(MAXR[index], P[index]);
    }

    int ans = 0;

    rep(i, s.size())
    {
        const int index = s[i] - 'A';
        if (i + MAXL[index] < 0) { continue; }
        if (i + MAXR[index] >= N) { continue; }

        ++ans;
    }

    cout << ans << endl;

    return 0;
}
