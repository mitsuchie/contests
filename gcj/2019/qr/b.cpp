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

int T;
int N;
string S;

int main()
{
    cin >> T;
    rep(i, T)
    {
        cin >> N;
        cin >> S;

        const auto sn = S.size();

        const auto c1 = S[0];
        const auto c2 = S[sn - 1];

        cout << "Case #" << (i + 1) << ": ";

        if (c1 != c2)
        {
            rep(i, N - 1) { cout << c2; }
            rep(i, N - 1) { cout << c1; }
            cout << endl;
        }
        else
        {
            const auto cc = c1 == 'E' ? 'S' : 'E';

            int p = 0, q = 0;

            rep(i, S.size() - 1)
            {
                if (S[i] == cc) { ++q; }
                if (S[i] == cc && S[i + 1] == cc) { p = q; }
            }

            rep(i, p) { cout << cc; }
            rep(i, N - 1) { cout << c1; }
            rep(i, N - p - 1) { cout << cc; }
            cout << endl;
        }
    }

    return 0;
}
