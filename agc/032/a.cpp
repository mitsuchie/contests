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
using pii = pair<int, int>;

int W, H, R;

const int MAXN = 1024;
char M[MAXN][MAXN];

const int MAXA = MAXN * MAXN;
int  COST[MAXA];

int calcIndex(int x, int y) { return x + y * W; }
int toX(int index) { return index % W; }
int toY(int index) { return index / W; }

int main()
{
    cin >> H >> W;

    rep(y, H) { cin >> M[y]; M[y][W] = 0; }

    priority_queue< pii, vector<pii>, greater<pii> > Q;

    fill(COST, COST + MAXA, -1);

    rep(y, H)
    rep(x, W)
    {
        if (M[y][x] != '#') { continue; }

        const int index = calcIndex(x, y);

        Q.push(pii(0, index));
        COST[index] = 0;
    }

    while(!Q.empty())
    {
        const auto current = Q.top();
        Q.pop();

        const int x = toX(current.second);
        const int y = toY(current.second);

        static const int dx[] = { -1, 1,  0, 0 };
        static const int dy[] = {  0, 0, -1, 1 };

        rep(i, 4)
        {
            const int xx = x + dx[i];
            const int yy = y + dy[i];

            if (xx < 0 || W <= xx) { continue; }
            if (yy < 0 || H <= yy) { continue; }

            const int index = calcIndex(xx, yy);
            if (COST[index] != -1) { continue; }

            COST[index] = current.first + 1;
            Q.push(pii(COST[index], index));
        }
    }

    int ans = 0;

    rep(i, MAXA)
    {
        ans = max(ans, COST[i]);
    }

    cout << ans << endl;

    return 0;
}
