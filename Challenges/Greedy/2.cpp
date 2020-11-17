#include <bits/stdc++.h>
using namespace std;

int main () {

	int n; cin>>n;
	vector <pair<int,int>> v;
	for(int i=0;i<n;i++)
	{
		int a,b; cin>>a>>b;
		v.push_back({a,b});
	}

	int l,p; cin>>l>>p;

	int start=0; int count=1; 
	while(true)
	{
		int max = -1;
		for(int i=start;true;i++)
		{
			if(v[i].first<(l-p))
				break;
			int fuel_left = p-(l-v[i].first);
			int new_fuel = fuel_left+v[i].second;
			int new_l = new_fuel+l-v[i].first;
			if(new_fuel>max)
			{
				max = new_fuel;
				start = i;
			}
		}

		count++;
		l=v[start].first;
		if((l-p)<=0)
			break;
	}

	cout<<count<<endl;


	return 0;
}