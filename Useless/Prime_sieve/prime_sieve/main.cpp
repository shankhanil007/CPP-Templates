#include<iostream>
using namespace std;

int main()
{
    int arr[10005]={0};
    int prime[10005];
	int count[10005]={0};
	long long int sum=0;
    for(int i=3;i<=10000;i+=2)
    {
        arr[i]=1;
    }

    for(long long int i=3;i<=10000;i+=2)
    {
        if(arr[i]==1)
        {
            for(long long int j=i*i;j<=10000;j+=i)
            {
                arr[j]=0;
            }
        }
    }

    arr[0]=arr[1]=0;
    arr[2]=1;
    for(long long int i=0;i<=10000;i++)
    {
    		if(arr[i]==1)
            {
				sum++;
				count[i]=sum;
			}
			else
				count[i]=sum;

    }

    int x=0;
	for(long long int i=0;i<=10000;i++)
	{
		if(arr[i]==1)
		{
			prime[x]=i;
			x++;
		}
	}


	int n;
	cin>>n;


// Calculating prime factors

/* int i=0;
int p=prime[0];

while(p*p<=n)
{
    if(n%p==0)
    {
        cout<<p<<" ";
        while(n%p==0)
        {
            n/=p;
        }
    }
    i++;
    p=prime[i];
}

if(n!=1)
    cout<<n;

	return 0;
} */




//counting divisors

/*int i=0;
int p=prime[0];
int ans=1;

while(p*p<=n)
{
    int count=0;
    if(n%p==0)
    {
        while(n%p==0)
        {
            count++;
            n/=p;
        }
    }
    ans=ans*(count+1);
    i++;
    p=prime[i];
}

if(n!=1)
{
    ans*=2;
}

cout<<ans;

	return 0;
}
*/



//large prime
