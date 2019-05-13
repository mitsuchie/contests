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
    int T;
    cin >> T;

    rep(i, T)
    {
        string s;
        cin >> s;

        string a, b;

        rep(j, s.size())
        {
            if (s[j] == '4')
            {
                a.push_back('3');
                b.push_back('1');
            }
            else
            {
                a.push_back(s[j]);
                if (b.size() != 0) { b.push_back('0'); }
            }
        }

        cout << "Case #" << i + 1 << ": " << a << " " << b << endl;
    }

    return 0;
}
