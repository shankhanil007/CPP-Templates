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

bool compare(pair<ll,ll> a, pair<ll,ll> b)
{
	return a.second<b.second;
}

int main() {

	ll n; cin>>n;
	vector <pair<ll, ll>> v;
	for(int i=1;i<=n;i++)
	{
		ll a,b; cin>>a>>b;
		v.push_back({a-b,a+b});
	}

	sort(v.begin(),v.end(),compare);

	ll count = 0; pair <int, int> p=v[0];
	for(int i=1;i<n;i++)
	{
		if(v[i].first<p.second)
		{
			count++;
		}
		else
			p = v[i];
	}

	cout<<count<<endl;

	return 0;
}