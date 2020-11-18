#include<iostream>
using namespace std;

int main () {

	int n; cin>>n;
	int arr[n];	 int sum = 0;
	for(int i=0;i<n;i++)
	{
		int no; cin>>no;
		sum+=no;
		arr[i]=sum;
	}

	if((arr[n-1]%n)!=0)
		cout<<"-1"<<endl;
	
	else
	{
		int equal = arr[n-1]/n; int m = -1;
		for(int i=1;i<=n-1;i++)
		{
			int left = arr[i-1];
			int right = arr[n-1]-arr[i-1];
			int lex = abs(left-i*equal);
			int rex = abs(right - (n-i)*equal);
			int mx = max(lex,rex);
			m = max(mx,m);
		}
		cout<<m<<endl;
	}



	return 0;
}