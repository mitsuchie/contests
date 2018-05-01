#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T, N;

int solve(const vector<int>& a, const vector<int>& b)
{
    const int AN = a.size();
    const int BN = b.size();

    for(int i=0,n=(N/2)+1;i<n;++i)
    {
        if (i<AN && i<BN)   { if (a[i] > b[i])     { return i * 2; }     }
        if (i<BN && i+1<AN) { if (b[i] > a[i + 1]) { return i * 2 + 1; } }
    }

    return -1;
}

int main()
{
    cin >> T;

    for(int t=0;t<T;++t)
    {
        cin >> N;
        const int AN = ((N + 1) / 2);
        const int BN = ((N + 0) / 2);

        vector<int> A, B;
        A.assign(AN, 0);
        B.assign(BN, 0);

        for(int i=0;i<AN;++i)
        {
            cin>>A[i];
            if (i < BN) { cin>>B[i]; }
        }

        // for(int i=0;i<AN;++i) { cout<<A[i]; } cout<<endl;
        // for(int i=0;i<BN;++i) { cout<<B[i]; } cout<<endl;

        sort(A.begin(), A.end());
        sort(B.begin(), B.end());

        // for(int i=0;i<AN;++i) { cout<<A[i]; } cout<<endl;
        // for(int i=0;i<BN;++i) { cout<<B[i]; } cout<<endl;

        int ans = solve(A, B);

        cout<<"Case #"<<(t+1)<<": ";
        if (ans == -1) { cout<<"OK"; } else { cout<<ans; }
        cout<<endl;
    }

    return 0;
}
