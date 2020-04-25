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

int main()
{
    ll N;
    cin >> N;

    vector<ll> A(N);
    for (auto& a : A) { cin >> a; }

    sort(A.begin(), A.end());

    ll x = -1, y = -1, z = -1;
    ll xn = 0, yn = 0, zn = 0;

    bool ok = true;

    for (const auto& a : A)
    {
        if (x == -1 || x == a)
        {
            x = a;
            ++xn;
        }
        else if (y == -1 || y == a)
        {
            y = a;
            ++yn;
        }
        else if (z == -1 || z == a)
        {
            z = a;
            ++zn;
        }
        else
        {
            ok = false;
        }
    }

    // 全部 0 パターン
    if (x == 0 && xn == N)
    {
        cout << "Yes" << endl;
        return 0;
    }

    // X 0 X 0 X or X 0 X X 0 X のパターン
    if (x == 0 && yn != -1 && z == -1 && (xn + 1 == yn || xn * 2 == yn || xn * 2 + 1 == yn))
    {
        cout << "Yes" << endl;
        return 0;
    }

    // 他に 0 があるとダメ
    if (x == 0)
    {
        cout << "No" << endl;
        return 0;
    }

    // 3種類の数字を使っているかどうか
    if (x == -1 || y == -1 || z == -1)
    {
        ok = false;
    }

    // 3種類の数字の出現頻度が同じかどうか
    if (!(xn == yn && yn == zn))
    {
        ok = false;
    }

    if (!((x ^ z) == y && (y ^ x) == z && (z ^ y) == x))
    {
        ok = false;
    }

    cout << (ok ? "Yes" : "No") << endl;

    return 0;
}
