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
int A[MAXN];
int B[MAXN];
int N;

vector<int> ls;
vector<int> rs;

int main()
{
    cin >> N;
    rep(i, N) { cin >> A[i]; }
    rep(i, N) { cin >> B[i]; }

    rep(i, N)
    {
        if (A[i] < B[i]) { ls.push_back(B[i] - A[i]); }
        if (A[i] > B[i]) { rs.push_back(A[i] - B[i]); }
    }

    sort(ls.begin(), ls.end(), greater<int>());
    sort(rs.begin(), rs.end(), greater<int>());

    const auto rbase(rs);

    auto solve = [&]()
    {
        if (ls.size() == 0) { return 0; }

        int ri = 0;

        rep(li, ls.size())
        {
            int l = ls[li];

            while(l != 0 && ri < rs.size())
            {
                if (l <= rs[ri]) { rs[ri] -= l; l = 0; }
                else             { l -= rs[ri]; rs[ri] = 0; ++ri; }
            }

            if (l != 0) { return -1; }
        }

        return static_cast<int>(ls.size()) + (ri + (rs.size() <= ri || rbase[ri] == rs[ri] ? 0 : 1));
    };

    // for (const auto& n : ls) { cout<<n<<" "; } cout<<endl;
    // for (const auto& n : rs) { cout<<n<<" "; } cout<<endl;

    int ans = solve();
    cout << ans << endl;

    return 0;
}
