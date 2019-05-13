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

const int N = 5;
int K;
int X[N];

int main()
{
    rep(i, N) { cin >> X[i]; }
    cin >> K;

    int ans = 0;

    for (int i=0;i<N;++i)
    {
        for (int j=i+1;j<N;++j)
        {
            if (std::abs(X[j] - X[i]) > K) { ++ans; }
        }
    }

    cout << (ans == 0 ? "Yay!" : ":(") << endl;

    return 0;
}
