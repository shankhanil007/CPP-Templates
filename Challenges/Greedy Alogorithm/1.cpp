#include <bits/stdc++.h>
using namespace std;


bool compare(pair<int,int> a, pair<int,int> b)
{
	return a.second<b.second;
}



int main() {

	int q; cin>>q;
	for(int w=1;w<=q;w++)
	{
		int n; cin>>n;
		vector <pair<int,int>> v;

		for(int i=0;i<n;i++)
		{
			int start,end; cin>>start>>end;
			v.push_back({start,end});
		}

		sort(v.begin(),v.end(),compare);

		int count=1; pair <int, int> p;
		p = v[0];
		for(int i=1;i<n;i++)
		{
			if(v[i].first>=p.second)
			{
				p=v[i];
				count++;
			}
		}

		cout<<count<<endl;
	}


	return 0;
}