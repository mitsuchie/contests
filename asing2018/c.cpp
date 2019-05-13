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

const int MAXN = 401;
char S[MAXN][MAXN];
int  G[MAXN][MAXN];

int W, H;

void dfs(int x, int y, ll* rx, ll* ry)
{
    if (G[y][x]) { return; }
    G[y][x] = 1;

    if (S[y][x] == '.') { (*rx) += 1; } else { (*ry) += 1; }

    if (x + 1 < W  && S[y][x] != S[y][x + 1]) { dfs(x + 1, y, rx, ry); }
    if (y + 1 < H  && S[y][x] != S[y + 1][x]) { dfs(x, y + 1, rx, ry); }
    if (x - 1 >= 0 && S[y][x] != S[y][x - 1]) { dfs(x - 1, y, rx, ry); }
    if (y - 1 >= 0 && S[y][x] != S[y - 1][x]) { dfs(x, y - 1, rx, ry); }
}

int main()
{
    cin >> H >> W;
    rep(i, H) { cin >> S[i]; }

    ll ans = 0;

    rep(y, H)
    rep(x, W)
    {
        ll rx = 0, ry = 0;

        dfs(x, y, &rx, &ry);
        ans += rx * ry;
    }

    cout << ans << endl;

    return 0;
}
