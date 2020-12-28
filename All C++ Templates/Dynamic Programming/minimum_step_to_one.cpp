#include<bits/stdc++.h>
#include<climits>
using namespace std;
 
#define pb push_back
#define mp make_pair
#define ll long long int 
#define fo(i,n) for(i=0;i<n;i++)
#define set(a) memset(a,0,sizeof(a))
#define MOD 1000000007
#define test(t) ll t; cin>>t; while(t--)

ll min_step_to_one_Bottom_up(ll n,ll DP[])
{
    DP[1]=0;
    

    for(ll i=2;i<=n;i++)
    {
    	ll op1,op2,op3;
        op1=op2=op3=INT_MAX;
        
        if(n%3==0)
        {
        	op1 = DP[i/3];
        }
        if(n%2==0)
        {
        	op2 = DP[i/2];
        }
        op3 = DP[i-1];
        
        DP[i] = min(min(op1,op2),op3)+1;
    }

    return DP[n];
}


ll min_step_to_one_Top_down(ll n,ll DP[])
{
    // base case
    if(n==1)
    return 0;

    // recurring case
    // look up
     
     if(DP[n]!=0)
     return DP[n];

     // compute if DP[n] is not known 
     ll op1,op2,op3;
     op1=op2=op3=INT_MAX;

     if(n%3==0)
     op1=min_step_to_one_Top_down(n/3,DP)+1;

     if(n%2==0)
     op2=min_step_to_one_Top_down(n/2,DP)+1;

     op3=min_step_to_one_Top_down(n-1,DP)+1;

     ll ans=min(min(op1,op2),op3);

     return DP[n]=ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

        ll n;
        cin>>n;

        ll DP[100]={0};

        cout<<min_step_to_one_Bottom_up(n,DP)<<endl;
    
    return 0;
}