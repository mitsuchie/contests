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


int main()
{
    int N;
    string A, B, C;

    cin >> N;
    cin >> A >> B >> C;

    int ans = 0;

    rep(i, N)
    {
        int res = 0;

        if (A[i] != B[i] && A[i] != C[i] && B[i] != C[i]) { ans += 2; }
        else if (A[i] != B[i] && A[i] == C[i] && B[i] == C[i]) { ++ans; }
        else if (A[i] == B[i] && A[i] != C[i] && B[i] == C[i]) { ++ans; }
        else if (A[i] == B[i] && A[i] == C[i] && B[i] != C[i]) { ++ans; }
        else if (A[i] == B[i] && A[i] != C[i] && B[i] != C[i]) { ++ans; }
        else if (A[i] != B[i] && A[i] == C[i] && B[i] != C[i]) { ++ans; }
        else if (A[i] != B[i] && A[i] != C[i] && B[i] == C[i]) { ++ans; }

        // cout << i << ": " << A[i] << B[i] << C[i] << " "<< ans << endl;
    }

    cout << ans << endl;

    return 0;
}
