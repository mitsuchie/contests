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

const ll INF = 10000000001;
ll X, Y, Z, K;

const int MAXN = 1024;
ll xs[MAXN], ys[MAXN], zs[MAXN];

struct Vertex
{
    ll xi, yi, zi, value;

    Vertex(ll xxi, ll yyi, ll zzi)
    : xi(xxi), yi(yyi), zi(zzi), value(xs[xxi] + ys[yyi] + zs[zzi]) {}
};

bool operator< (const Vertex& a, const Vertex& b)
{
    return a.value < b.value;
}

bool dp[MAXN][MAXN][MAXN];

int main()
{
    cin >> X >> Y >> Z >> K;

    rep(i, X) { cin >> xs[i]; }
    rep(i, Y) { cin >> ys[i]; }
    rep(i, Z) { cin >> zs[i]; }

    std::sort(xs, xs + X, std::greater<ll>());
    std::sort(ys, ys + Y, std::greater<ll>());
    std::sort(zs, zs + Z, std::greater<ll>());

    std::priority_queue<Vertex> Q;

    const auto push = [&](ll xi, ll yi, ll zi) {
        if (xi >= X || yi >= Y || zi >= Z) { return; }
        if (dp[xi][yi][zi]) { return; }

        Q.push(Vertex(xi, yi, zi));
        dp[xi][yi][zi] = true;

    };

    Q.push(Vertex(0, 0, 0));
    dp[0][0][0] = true;

    rep(i, K)
    {
        if (Q.empty()) { break; }

        const Vertex v = Q.top();
        Q.pop();

        cout << v.value << endl;

        push(v.xi + 1, v.yi, v.zi);
        push(v.xi, v.yi + 1, v.zi);
        push(v.xi, v.yi, v.zi + 1);
    }

    return 0;
}
