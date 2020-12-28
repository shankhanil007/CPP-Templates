#include<bits/stdc++.h>
using namespace std;
 

#define ll long long

// fuction for top to bottom approach

ll min_coin_change_top_down(ll n,ll *coins,ll t,ll *DP)
{
    //base case
    if(n==0)
    return 0;

    // memorisation
    if(DP[n]!=0)
    return DP[n];

    // recurrring case
    ll ans=INT_MAX;
    for(ll i=0;i<t;i++)
    {
        if(n-coins[i]>=0)
        {
            ll subproblem=min_coin_change_top_down(n-coins[i],coins,t,DP);
            ans=min(ans,subproblem+1);
        }
    }

    DP[n]=ans;
    return DP[n];
}

// fucntion for bottom to top approach 

ll min_coin_change_bottom_top(ll n,ll *coins,ll t,ll *DP)
{
    DP[0]=0;

    for(ll i=1;i<=n;i++)
    {
        ll ans=INT_MAX;
        for(ll j=0;j<t;j++)
        {
            if(i-coins[j]>=0)
            {
                ans=min(DP[i-coins[j]],ans);
            }
        }
        DP[i]=ans+1;
    }

    return DP[n];
}

int main()
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        
        
        ll n;
        cin>>n;
        
        ll coins[]={1,7,10};
        ll DP[100]={0};
        ll t=sizeof(coins)/sizeof(ll);

        cout<<min_coin_change_top_down(n,coins,t,DP)<<endl;
        
    return 0;
}