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
// using det1 = vector< vector<ll> >
// using det2 = vector< vector<pll> >

const int MAXN = 6;
int N;


int main()
{
    int T;
    cin >> T;

    rep(t, T)
    {
        cin >> N;

        vector<string> S(N);
        rep(i, N) { cin >> S[i]; }

        int ans = 0;

        for (int i=0;i<N;++i)
        for (int j=i+1;j<N;++j)
        {
            const int lhs = S[i].size();
            const int rhs = S[j].size();

            const int size = std::min<int>(lhs, rhs);

            int length = 0;

            for (int k=0;k<size;++k) 
            {
                if (S[i][lhs - k -1] == S[j][rhs - k - 1])
                {
                    ++length;
                }
                else
                {
                    break;
                }
            }

            if (length >= 2)
            {
                ++ans;
            }
        }

        printf("Case #%d: %d\n", t, ans);
    }

    return 0;
}
