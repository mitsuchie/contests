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
#include <tuple>
using namespace std;

#define REP(i,p,n) for(int i=p;i<n;++i)
#define rep(i,n) REP(i,0,n)

using ll = long long int;
using pll = pair<ll, ll>;

int main()
{
    ll N;
    cin >> N;

    vector<ll> A(N);
    for (auto& a : A) { cin >> a; }

    sort(A.begin(), A.end());

    {
        ll M = A[A.size() - 1] - A[0];

        ll index = 1;
        while (index < N - 1 && A[index] <= 0) { M -= A[index]; ++index; }
        while (index < N - 1) { M += A[index]; ++index; }

        cout << M << endl;
    }

    {
        ll M = A[A.size() - 1];

        ll index = 1;

        while (index < N - 1 && A[index] <= 0)
        {
            cout << M << " " << A[index] << endl;
            M -= A[index];
            ++index;
        }

        ll t = A[0];

        while (index < N - 1)
        {
            cout << t << " " << A[index] << endl;
            t -= A[index];
            ++index;
        }

        cout << M << " " << t << endl;
        M -= t;
    }

    return 0;
}
