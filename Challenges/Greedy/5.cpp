#include <bits/stdc++.h>
using namespace std;

bool compare(pair <int, int> a,pair <int, int> b)
{
	return a.first<b.first;
}

bool comp(pair <int, int> a,pair <int, int> b)
{
	return a.second<b.second;
}

int main() {

	int n; cin>>n;	
	vector <pair<int,int>> pos;
	for(int i=0;i<n;i++)
	{
		int a,b; cin>>a>>b;
		pos.push_back({a,b});
	}

	vector <int> x,y;
	sort(pos.begin(),pos.end(),compare);


	for(int i=1;i<n;i++)
	{
		x.push_back(pos[i].first-pos[i-1].first-1);
	}

	sort(pos.begin(),pos.end(),comp);

	for(int i=1;i<n;i++)
	{
		y.push_back(pos[i].second-pos[i-1].second-1);
	}

	sort(x.begin(),x.end());
	sort(y.begin(),y.end());

	cout<<x[x.size()-1]*y[y.size()-1]<<endl;

	return 0;
}