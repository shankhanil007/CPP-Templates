#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define pb push_back
#define deb(x) cout<<#x<<" : "<<x<<"\n";
#define debug(x,y) cout<<#x<<" : "<<x<<"\t"<<#y<<" : "<<y<<"\n";
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define setp(n) cout << fixed << setprecision(n)
#define mset(x,y) memset(x,y,sizeof(x))
#define mp(x,y) make_pair(x,y)
#define checkbit(x,i) (x&(1ll<<i))?1:0
#define setbit(x,i) x|(1ll<<i)
#define compbit(x,i) x^(1ll<<i)
#define ff first
#define ss second
#define mod 1000000007
#define N 100010
int main() {

	int q; cin>>q;
	for(int w=1;w<=q;w++)
	{
		int n; cin>>n;
		int arr[n];
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		if(n==1)
		{
			cout<<arr[0]<<" "<<arr[0]<<endl;
		}
		else
		{
			sort(arr,arr+n);
			int s=0,e=n-1; ll max = 0;
			while(s<=e)
			{
				max += abs(arr[s]-arr[e]);
				s++;
				e--;
			}
			ll min=0;
			for(int i=0;i<n;i+=2)
			{
				min += abs(arr[i]-arr[i+1]);
			}
			cout<<min<<" "<<max<<endl;
		}
		
	}


	return 0;
}