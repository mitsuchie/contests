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

const int MAXR=6;
ll R[MAXR];

void solve()
{
    ll d6, d7;
    cout << 6 << endl; cin >> d6;
    cout << 7 << endl; cin >> d7;
    R[0] = (d7 - d6) / 64;

    ll d2, d3;
    cout << 2 << endl; cin >> d2;
    cout << 3 << endl; cin >> d3;
    R[2] = (d3 - d2 - R[0] * 4);

    /*
    ll d1, d2;
    cout << 1 << endl; cin >> d1;
    cout << 2 << endl; cin >> d2;
    R[1] = (d2 - d1 - R[0] * 2);

    ll d3;
    cout << 3 << endl; cin >> d3;
    R[2] = (d3 - d2 - R[0] + 4);

    // ll d4;
    // cout << 4 << endl; cin >> d4;
    // R[3] = (d4 - d3 - R[0] * 8 - R[1] * 2);

    ll d5;
    cout << 5 << endl; cin >> d5;
    R[6] = (d6 - d5 - R[0] * 32 - R[1] * 4);
    */


}

int main()
{
    int T, W;
    cin >> T >> W;

    rep(t, T)
    {
        solve();

        rep(i, MAXR) { cout << R[i] << " "; }
        cout << endl;

        int judge = -1;
        cin >> judge;

        if (judge == -1) { break; }
    }

    return 0;
}
