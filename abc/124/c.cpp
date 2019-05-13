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

int main()
{
    string s;
    cin >> s;

    const int n = s.size();

    int a = 0;
    int b = 0;

    rep(i, n)
    {
        if ((i % 2 == 0))
        {
            if (s[i] == '0') { ++a; }
            if (s[i] == '1') { ++b; }
        }
        else
        {
            if (s[i] == '1') { ++a; }
            if (s[i] == '0') { ++b; }
        }
    }

    cout << std::min<int>(a, b) << endl;

    return 0;
}
