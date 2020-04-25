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

const ll MAXN = 100000;
ll X[MAXN];
ll Y[MAXN];
ll Z[MAXN];

struct UnionFind
{
    vector<int> uf;

    // 親なし(-1)で初期化しておく
    void init(int n) { uf.assign(n, -1); }

    // 親がいないなら自分を返す, 親がいたら経路圧縮して返す(root直下に繋ぐ)
    int find(int x) { return uf[x] < 0 ? x : (uf[x] = this->find(uf[x])); }

    // 繋げようとする(unionは予約語なんですよね, これが)
    bool connect(int a, int b)
    {
        a = this->find(a); // aのルートノード
        b = this->find(b); // bのルートノード
        if (a != b){ uf[b] = a; return true; } // 新しくつなげた
        return false; // もうつながってる
    }

} uf;


int main()
{
    cin >> N >> M;
    // rep (i, M) { cin >> X[i] >> Y[i] >> Z[i]; }

    uf.init(N);

    ll x, y, z;

    rep(i, M)
    {
        cin >> x >> y >> z;
        --x;
        --y;

        uf.connect(x, y);
    }


    ll ans = 0;

    rep(i, N)
    {
        if (uf.uf[i] < 0) { ++ans; }
    }

    cout << ans << endl;

    return 0;
}
