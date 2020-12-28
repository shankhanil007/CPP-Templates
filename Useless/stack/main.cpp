#include <iostream>
#include <stack>
using namespace std;


// reverse a stack using ONE stack recursion

/*void bottom(stack <int>& s, int x)
{
    if(s.empty())
    {
        s.push(x);
        return;
    }

    int y=s.top();
    s.pop();

    bottom(s,x);
    s.push(y);
}


void reverse_rec(stack <int>& s)
{
    if(s.empty())
        return;

    int x=s.top();
    s.pop();
    reverse_rec(s);

    bottom(s,x);
}

int main()
{
    stack <int> s;
    for(int i=1;i<=5;i++)
    {
        s.push(i);
    }

    reverse_rec(s);

    while(!s.empty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }

    return 0;
}*/






//reverse a stack using TWO stacks only

/*void transfer(stack <int>& s1, stack <int>& s2,int n)
{
   for(int i=0;i<n;i++)
   {
       s2.push(s1.top());
       s1.pop();
   }

}


void reverse(stack <int>& s1)
{
    int n=s1.size();


    for(int i=0;i<s1.size();i++)
    {
        stack <int> s2;
        int top=s1.top();
        s1.pop();
        transfer(s1,s2,n-i-1);
        s1.push(top);
        transfer(s2,s1,n-i-1);
    }

}



int main()
{
    stack <int> s;
    for(int i=1;i<=5;i++)
    {
        s.push(i);
    }

    reverse(s);

    while(!s.empty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }

    return 0;
}*/





// FInd the next greater element in an array

/*#include<iostream>
#include <stack>
using namespace std;

int main() {

	int n; cin>>n;
	int arr[n];	int ans[n];
	stack <int> s;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}


	for(int i=0;i<n;i++)
	{
		if(s.empty())
		{
			s.push(arr[i]);
		}


		else
		{
			while(!s.empty() && s.top()<arr[i])
			{
				s.pop();
			}
			s.push(arr[i]);
		}

	}

	while(!s.empty())
	{
		cout<<"-1 ";
		s.pop();
	}



	return 0;
}*/





// HISTOGRAM area problem

/*#include<iostream>
#include<stack>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int main() {

	ll n; cin>>n;
	ll arr[n]; ll max=0;
	stack <ll> s;

	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}

	int i=0;
	for(;i<n;i++)
	{

		if(s.empty())
			s.push(i);

		else
		{
			if(arr[i]>arr[s.top()])
			{
				s.push(i);
			}

			else
			{
				while(!s.empty() && arr[i]<arr[s.top()])
				{
					ll x=arr[s.top()];
					s.pop();
					ll area=0;

					if(s.empty())
					{
						area=x*i;
					}

					else
					{
						area=x*(i-s.top()-1);
					}

					if(area>max)
						max=area;

				}
				s.push(i);
			}
		}
	}

	while(!s.empty())
	{
		ll x=arr[s.top()];
		s.pop();
		ll area=0;

		if(s.empty())
		{
			area=x*i;
		}
		else
		{
			area=x*(i-s.top()-1);
		}
		//cout<<area<<endl;
		if(area>max)
			max=area;

	}


	cout<<max;

	return 0;
}*/
