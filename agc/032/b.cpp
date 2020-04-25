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

int W, H, N;
int X, Y;

string A;
string B;

bool isStableX()
{
    int lhs = 0, rhs = W - 1;

    rep (i, N)
    {
        const auto a = A[N - i - 1];
        const auto b = B[N - i - 1];

        if (b == 'L') { rhs = min(rhs + 1, W - 1); }
        if (b == 'R') { lhs = max(lhs - 1, 0); }

        if (a == 'L') { lhs += 1; }
        if (a == 'R') { rhs -= 1; }

        if (lhs > rhs) { return false; }
    }

    return lhs <= X && X <= rhs;
}

bool isStableY()
{
    int lhs = 0, rhs = H - 1;

    rep (i, N)
    {
        const auto a = A[N - i - 1];
        const auto b = B[N - i - 1];

        if (b == 'U') { rhs = min(rhs + 1, H - 1); }
        if (b == 'D') { lhs = max(lhs - 1, 0); }

        if (a == 'U') { lhs += 1; }
        if (a == 'D') { rhs -= 1; }

        if (lhs > rhs) { return false; }
    }

    return lhs <= Y && Y <= rhs;
}

int main()
{
    cin >> H >> W >> N;
    cin >> Y >> X;
    cin >> A >> B;

    --X;
    --Y;

    if (isStableX() && isStableY())
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
