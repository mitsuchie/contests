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

const int MAXN=100000;
int N;

struct Job { int id, t1, t2; };
vector<Job> jobs;
det1 ids;

bool operator<(const Job& a,const Job& b)
{
	return a.t1 < b.t1 ? true : a.t1 > b.t1 ? false :
		   a.t2 < b.t2 ? true : a.t2 > b.t2 ? false :
		   a.id < b.id;
}

int main()
{
	cin>>N;
	jobs.assign(N,Job());

	rep(i,N){ cin>>jobs[i].t1>>jobs[i].t2; jobs[i].id=i+1; }

	sort(jobs.begin(),jobs.end());
	// rep(i,jobs.size()){ cout<<(jobs[i].id)<<": "<<(jobs[i].t1)<<" => "<<(jobs[i].t2)<<endl; }

	int ans = 0;

	rep(j,N)
	{
		int t = 0, res = 0;
		vint tmp;
		REP(i,j,N){ if(t<=jobs[i].t1){ t=jobs[i].t2; ++res; tmp.push_back(jobs[i].id);} }

		if(ans<res)
		{
			ans = res;
			ids.clear();
			ids.push_back(tmp);
		}
		else if(ans==res)
		{
			ids.push_back(tmp);
		}
	}

	sort(ids.begin(),ids.end());

	cout<<ans<<endl;
	// rep(j,ids.size()){ cout<<j<<": "; rep(i,ids[j].size()){ cout<<ids[j][i]<<" "; } cout<<endl; }
	rep(i,ids[0].size()){ cout<<ids[0][i]<<" "; } cout<<endl;

	return 0;
}
