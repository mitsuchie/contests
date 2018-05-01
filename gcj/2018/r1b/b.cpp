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

const int MAXN=100000;
int S;
int D[MAXN];
int A[MAXN];
int B[MAXN];

pii solve()
{
    int amax = 0, bmax = 0;

    rep(i, S)
    {
        int am = 0, bm = 0;

        rep(j, S)
        {
            if (i == j) { continue; }

            const int la = D[i] + A[i];
            const int ra = D[j] + A[j];
            const int lb = D[i] - B[i];
            const int rb = D[j] - B[j];

            if (la == ra && lb == rb) { ++am; ++bm; }
            else if (la == ra) { ++am; }
            else if (lb == rb) { ++bm; }
        }

        amax = max(amax, am);
        bmax = max(bmax, bm);
    }

    return pii(amax, bmax);
}

int main()
{
    int t;
    cin>>t;

    rep(i, t)
    {
        cin>>S;
        rep(i, S) { cin>>D[i]>>A[i]>>B[i]; }

        auto ans = solve();

        cout<<"Case #"<<(i+1)<<": ";
        cout<<ans.first<<" "<<ans.second<<endl;
    }

    return 0;
}
