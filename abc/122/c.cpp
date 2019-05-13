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

const int MAXN = 100000;
const int MAXQ = 100000;
const int MAXD = 100;

string S;
int N;
int Q;
int D;

int dp[MAXN * 10];

int solve(ll index, int lhs, int rhs, int ql, int qr)
{
    if (rhs < ql || qr < lhs) { return 0; }
    if (ql <= lhs && rhs <= qr) { return dp[index]; }

    if (lhs == rhs) { return 0; }

    const int mid = (lhs + rhs) >> 1;

    const ll li = index * 2;
    const ll ri = index * 2 + 1;

    const int llhs = lhs;
    const int lrhs = max(lhs, mid);

    const int rlhs = min(rhs, mid + 1);
    const int rrhs = rhs;

    const int ln = solve(li, llhs, lrhs, ql, qr);
    const int rn = solve(ri, rlhs, rrhs, ql, qr);

    return ln + rn;
}

int countUp(ll index)
{
    if (index >= D) { return dp[index]; }

    const ll lhs = index * 2;
    const ll rhs = index * 2 + 1;

    const int ln = countUp(lhs);
    const int rn = countUp(rhs);

    return dp[index] = ln + rn;
}


int main()
{
    cin >> N >> Q;
    cin >> S;

    D = 1;
    while (D < N) { D = D << 1; }

    rep(i, N - 1) { if (S[i] == 'A' && S[i + 1] == 'C') { dp[D + i + 1] = 1; } }

    countUp(1);

    int ql, qr;

    rep(i, Q)
    {
        cin >> ql >> qr;
        --ql;
        --qr;

        const int ans = solve(1, 0, D - 1, ql, qr);
        const int offset = ql > 0 && S[ql - 1] == 'A' && S[ql] == 'C' ? 1 : 0;

        cout << ans - offset << endl;
    }

    return 0;
}
