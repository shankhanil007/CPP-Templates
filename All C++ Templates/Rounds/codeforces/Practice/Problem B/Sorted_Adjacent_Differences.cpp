
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long long
#define fo(i,n) for(i=0;i<n;i++)
#define set(a) memset(a,0,sizeof(a))
#define MOD 1000000007
#define test() ll t; cin>>t; while(t--)

int main ()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    test()
    {
        ll n,first,second,i;
        cin>>n;

        vector<ll>v(n);

        vector<ll>ans(n);


        for(i=0;i<n;i++)
        cin>>v[i];

        sort(v.begin(),v.end());

        first=0;
        second=n-1;

        for(i=0;i<n;i++)
        {
            if(i%2==0)
            {
                ans[i]=v[first];
                first++;
            }

            else if(i%2!=0)
            {
                ans[i]=v[second];
                second--;
            }
        }

        reverse(ans.begin(),ans.end());
        
        for(i=0;i<n;i++)
        cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}