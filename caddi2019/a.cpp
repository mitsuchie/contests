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

const int MAXL = 1000;
const int MAXN = 1000;
const int MAXM = 1000000;

int L, N, M;

// =============================================================================
//
// Sphere
//
// =============================================================================
class Sphere
{
public:
    explicit Sphere(int radius, int point)
    : mRadius(radius)
    , mPoint(point)
    {}



private:
    const int mRadius, mPoint;
};

// =============================================================================
//
// Bonus
//
// =============================================================================
class Bonus
{
public:
    explicit Bonus(int a, int b, int distance, int point)
    : mA(a)
    , mB(b)
    , mDistance(distance)
    , mPoint(point)
    {}

private:
    const int mA, mB, mDistance, mPoint;
};

int main()
{
    cin >> L >> N >> M;

    vector<Sphere> spheres;

    rep(i, L)
    {
        int radius, point;
        cin >> radius >> point;

        spheres.push_back(Sphere(radius, point));
    }

    vector<Bonus> bonuses;

    rep(i, M)
    {
        int a, b, distance, point;
        cin >> a >> b >> distance, point;

        --a;
        --b;

        bonuses.push_back(Bonus(a, b, distance, point));
    }

    return 0;
}
