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

const int MAXNM = 100000;

int N, M , NM;
vector<int> E[MAXNM];
vector<int> R[MAXNM];

int P[MAXNM];

int findRootIndex()
{
    rep(i, N)
    {
        if (R[i].size() == 0) { return i; }
    }

    return -1;
}

int main()
{
    cin >> N >> M;
    NM = N + M;

    int a, b;

    rep(i, NM - 1)
    {
        cin >> a >> b;
        --a;
        --b;

        E[a].push_back(b);
        R[b].push_back(a);
    }

    const int ri = findRootIndex();
    // cout<<"root="<<ri + 1<<endl;

    queue<int> Q;
    Q.push(ri);

    while (!Q.empty())
    {
        const int parentIndex = Q.front();
        Q.pop();

        rep(i, E[parentIndex].size())
        {
            const int childIndex = E[parentIndex][i];
            P[childIndex] = parentIndex + 1;

            // cout<<"parent:"<<parentIndex+1<<" child:"<<childIndex+1<<endl;
            Q.push(childIndex);
        }
    }

    rep(i, N) { cout << P[i] << endl; }

    return 0;
}
