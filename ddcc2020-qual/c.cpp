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

#define REP(i,p,n) for(ll i=p;i<ll(n);++i)
#define rep(i,n) REP(i,0,n)

using ll = long long int;
using pll = pair<ll, ll>;

const ll mod = static_cast<ll>(1e9) + 7;

ll H, W, K;
vector<string> S;

const ll MAXW = 300;
const ll MAXH = 300;
ll A[MAXH][MAXW];

int main()
{
    cin >> H >> W >> K;

    S.assign(H, string());
    for (auto& s : S) { cin >> s; }

    ll k = 1;

    // 上から順番に埋めていくパターン
    rep (y, H)
    {
        ll xx = -1;

        // 順番に埋めていく
        rep (x, W)
        {
            A[y][x] = k;
            if (S[y][x] == '#') { ++k; xx = x; }
        }

        // 見つかった場合は最後を埋めて終わらせる
        if (xx != -1)
        {
            REP(x, xx, W) { A[y][x] = k - 1; }
            continue;
        }

        // 見つからなかった場合は上の人に任せる
        rep (x, W)
        {
            if (y != 0 && A[y - 1][0] != 0)
            {
                A[y][x] = A[y - 1][x];
            }
            else
            {
                A[y][x] = 0;
            }
        }
    }

    // 下から順番に埋めていくパターン
    rep (y, H - 1)
    {
        const ll yy = H - y - 2;

        // 既に埋まっている
        if (A[yy][0] != 0) { continue; }

        rep (x, W)
        {
            A[yy][x] = A[yy + 1][x];
        }
    }

    rep (y, H)
    {
        rep (x, W) { cout << A[y][x] << " "; }
        cout << endl;
    }

    return 0;
}
