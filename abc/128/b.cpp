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

struct R
{
    string name;
    ll score;
    ll index;

    bool operator<(const R& r) const
    {
        if (this->name == r.name) { return this->score >= r.score; }
        return this->name < r.name;
    }
};


int main()
{
    ll n;
    cin >> n;

    vector<R> rs(n);

    rep(i, n)
    {
        cin >> rs[i].name >> rs[i].score;
        rs[i].index = i + 1;
    }

    sort(rs.begin(), rs.end());

    rep(i, n)
    {
        cout << rs[i].index << endl;
    }

    return 0;
}
