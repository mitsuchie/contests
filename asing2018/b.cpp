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

const int MAXN = 100;
int P[MAXN];

int main()
{
    int N, A, B;
    cin >> N >> A >> B;

    rep(i, N) { cin >> P[i]; }

    int p[3] = { 0 };

    rep(i, N)
    {
        const int pi = (P[i] <= A ? 0 : (P[i] <= B ? 1 : 2));
        ++p[pi];
    }

    sort(p, p + 3);

    cout << p[0] << endl;

    return 0;
}
