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

const int MAXN = 256;
string S[MAXN];
bool P[MAXN];

const int MAXC = 512;
char C[MAXC];

int T, A;

bool solve()
{
    fill(P, P + MAXN, true);
    fill(C, C + MAXC, 0);

    rep(si, 500)
    {
        bool gu = false, ch = false, pa = false;

        rep(ri, A)
        {
            const auto& s = S[ri];
            const auto  isAlive = P[ri];

            if (isAlive)
            {
                const int ssi = si % s.size();

                if (s[ssi] == 'R') { gu = true; }
                if (s[ssi] == 'S') { ch = true; }
                if (s[ssi] == 'P') { pa = true; }
            }
        }

        if (gu && ch && pa) { return false; }

        C[si] = gu && ch ? 'R'
              : ch && pa ? 'S'
              : pa && gu ? 'P'
              : gu ? 'P'
              : ch ? 'R'
              : pa ? 'S'
              : 0;

        if (gu && !(ch || pa)) { return true; }
        if (ch && !(gu || pa)) { return true; }
        if (pa && !(gu || ch)) { return true; }

        int wins = 0;

        rep(ri, A)
        {
            const auto& s = S[ri];
            const auto  isAlive = P[ri];

            if (isAlive)
            {
                const int ssi = si % s.size();
                if (s[ssi] == 'R' && C[si] == 'P') { P[ri] = false; }
                if (s[ssi] == 'S' && C[si] == 'R') { P[ri] = false; }
                if (s[ssi] == 'P' && C[si] == 'S') { P[ri] = false; }
            }

            if (!P[ri]) { ++wins; }
        }

        if (wins == A) { return true; }
    }

    return false;
}

int main()
{
    cin >> T;

    rep(t, T)
    {
        cin >> A;
        rep (i, A) { cin >> S[i]; }

        const bool ans = solve();

        if (ans)
        {
            printf("Case #%d: %s\n", t + 1, C);
        }
        else
        {
            printf("Case #%d: IMPOSSIBLE\n", t + 1);
        }
    }

    return 0;
}
