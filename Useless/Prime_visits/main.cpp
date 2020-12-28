#include<iostream>
using namespace std;

int main()
{
    int arr[1000005]={0};
	int count[1000005]={0};
	long long int sum=0;
    for(int i=3;i<=1000000;i+=2)
    {
        arr[i]=1;
    }

    for(long long int i=3;i<=1000000;i+=2)
    {
        if(arr[i]==1)
        {
            for(long long int j=i*i;j<=1000000;j+=i)
            {
                arr[j]=0;
            }
        }
    }

    arr[0]=arr[1]=0;
    arr[2]=1;
    for(long long int i=0;i<=1000000;i++)
    {
    		if(arr[i]==1)
            {
				sum++;
				count[i]=sum;
			}
			else
				count[i]=sum;

    }


	int q; cin>>q;
	for(int i=1;i<=q;i++)
	{
		int a,b; cin>>a>>b;
		long long int ans;
		if(count[a]==0 || (arr[a]==0 && arr[b]==0))
			 ans=count[b]-count[a];
		else
			ans=count[b]-count[a]+1;
		cout<<ans<<endl;
	}



	return 0;
}
