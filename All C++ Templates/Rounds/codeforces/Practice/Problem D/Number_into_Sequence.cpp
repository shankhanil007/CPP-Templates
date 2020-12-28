
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long long
#define fo(i,n) for(i=0;i<n;i++)
#define set(a) memset(a,0,sizeof(a))
#define MOD 1000000007
#define test() ll t; cin>>t; while(t--)


// ll p[10000000001]={0};

// void prime(ll *p)
// {
//     ll i,j;
//     for(i=3;i<=10000000001;i=i+2)
//     p[i]=1;

//     for(i=3;i*i<=10000000001;i=i+2)
//     {
//         if(p[i]==1)
//         {
//             for(j=i*i;j<=10000000001;j=j+i)
//             {
//                 p[j]=0;
//             }
//         }
//     }

//     p[0]=p[1]=0;
//     p[2]=1;
// }

int main ()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // prime(p);

    test()
    {
        ll n,i,cnt;
        cin>>n;

        ll temp=n;

        vector<pair<ll,ll>>v;

        cnt=0;

        while (n % 2 == 0)  
        {  
            // cout << 2 << " ";  
            n = n/2;  
            cnt++;
        }  

        if(cnt>0)
        v.push_back(make_pair(2,cnt));
    
        for (int i = 3; i <= sqrt(n); i = i + 2)  
        {  
            cnt=0;
            while (n % i == 0)  
            {  
                // cout << i << " ";  
                n = n/i;  
                cnt++;
            }
            if(cnt>0)
            v.push_back(make_pair(i,cnt));
        }  

        if (n > 2)  
        v.push_back(make_pair(n,1));

        ll max=INT_MIN,power,number;

        for(auto i:v)
        {
            if(i.second>max)
            {
                power=i.second;
                number=i.first;
                max=i.second;
            }
        }

        if(power==1)
        {
            cout<<1<<endl;
            cout<<temp<<endl;
        }

        else 
        {
            
            cout<<power<<endl;
            for(i=0;i<power-1;i++)
            {
                cout<<number<<" ";
                temp=temp/number;
            }

            cout<<temp<<endl;
        }
    
    }
    return 0;
}