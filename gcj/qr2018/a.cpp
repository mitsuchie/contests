#include <iostream>
#include <string>
using namespace std;

int N, D;
std::string S;

int eval()
{
    int d = 1, res = 0;

    for(auto s : S)
    {
        if (s == 'S') { res += d; }
        else          { d *= 2;   }
    }

    return res;
}

int findCS()
{
    for(int i=S.size()-2;i>=0;--i)
    {
        if (S[i] == 'C' && S[i+1] == 'S') { return i; }
    }

    return -1;
}

int solve()
{
    int res = 0, d = 0;

    while ((d = eval()) > D)
    {
        int index = findCS();
        if (index == -1) { return -1; }

        S[index + 0] = 'S';
        S[index + 1] = 'C';

        ++res;
    }

    // cout<<"i="<<res<<", D="<<D<<", d="<<d<<endl;
    return d != -1 && d <= D ? res : -1;
}

int main()
{
    cin>>N;

    for(int i=0;i<N;++i)
    {
        cin>>D>>S;

        int ans = solve();

        cout<<"Case #"<<i+1<<": ";
        if (ans == -1) { cout<<"IMPOSSIBLE"; } else { cout<<ans; }
        cout<<endl;
    }

    return 0;
}
