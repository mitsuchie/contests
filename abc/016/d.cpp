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

typedef complex<double> point;
vector<point> points;
point A, B;

double dot(const point& a,const point& b)
{
	return (a.real() * b.real() + a.imag() * b.imag());
}

double cross(const point& a,const point& b)
{
	return (a.real() * b.imag() - a.imag() * b.real());
}

bool is_intersected_ls(const point& a1,const point& a2,const point& b1,const point& b2)
{
	return (cross(a2-a1,b1-a1) * cross(a2-a1,b2-a1)) < 1e-3 &&
		   (cross(b2-b1,a1-b1) * cross(b2-b1,a2-b1)) < 1e-3;
}

int main()
{
	double x,y;
	cin>>x>>y; A = point(x,y);
	cin>>x>>y; B = point(x,y);

	int n;
	cin>>n;

	rep(i,n){ cin>>x>>y; points.push_back(point(x,y)); }

	int crossed_num = 0;
	rep(i,n)
	{
		const point& a = points[i];
		const point& b = points[(i+1)%n];

		crossed_num += (is_intersected_ls(a,b,A,B) ? 1 : 0);
	}

	cout<<(1+(crossed_num/2))<<endl;

	return 0;
}
