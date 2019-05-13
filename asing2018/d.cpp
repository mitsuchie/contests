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

int N, Q;

const int MAXN = 100000;
const int MAXQ = 100000;
int A[MAXN], X[MAXQ];

int XX;


int main()
{
    cin >> N >> Q;
    rep(i, N) { cin >> A[i]; }
    rep(i, Q) { cin >> X[i]; }

    int n = (N / 2) + 1;

    rep(i, Q)
    {
        sort(A, A + N, [i](int a, int b) -> int {
            const int lhs = abs(a - X[i]);
            const int rhs = abs(b - X[i]);
            if (lhs >= rhs) { return true; }

            return a >= b;
        });

        int ans = 0;
        rep(j, n) { ans += A[j]; }
        rep(j, N) { cout<<A[j]<<" "; } cout<<endl;

        cout << ans << endl;

    }

    return 0;
}
