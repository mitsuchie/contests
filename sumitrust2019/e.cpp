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

ll N;

const ll MAXN = 100000;
ll A[MAXN];

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
    cin >> N;
    rep (i, N) { cin >> A[i]; }

    uf.init(N);




    return 0;
}
