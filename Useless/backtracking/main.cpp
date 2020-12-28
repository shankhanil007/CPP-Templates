#include <iostream>
#include <string>
#include <set>
#include <string>
#include <cstring>
using namespace std;


// permutations of a string

/*void swap(char *temp, int i, int j)
{
	//cout<<temp<<" ";
	char t=temp[i];
	temp[i]=temp[j];
	temp[j]=t;
	//cout<<temp<<endl;
}



void find(char input[1000], char output[1000], int i, int j, int x)
{
	if(input[i]=='\0')
	{
		cout<<input<<endl;
		return;
	}

	for(int k=i;input[k]!='\0';k++)
	{
		char st[sizeof(input)];
		strcpy(st, input);
		swap(input,i,k);
		//cout<<st<<endl;
		//output[x]=st[i];
		find(input, output, i+1, j, x+1);
		swap(input,i,k);
	}

}

int main() {

	char st[1000];
	cin>>st;
	int n=strlen(st);
	//cout<<n<<endl;
	char output[1000];
	find(st,output, 0,n,0);

	return 0;
}*/




// set data structure unique permutations

void swap(char *temp, int i, int j)
{
	char t=temp[i];
	temp[i]=temp[j];
	temp[j]=t;
}

void find(char input[1000], int i, int j, int x, set<string> &s)
{
	if(input[i]=='\0')
	{
		string t=input;
		s.insert(t);
		return;
	}

	for(int k=i;input[k]!='\0';k++)
	{
		swap(input,i,k);
		find(input,i+1, j, x+1,s);
		swap(input,i,k);
	}

}

int main() {

	char st[1000];
	cin>>st;
	int n=strlen(st);

	set<string> s;

	find(st,0,n,0,s);

	for(auto str : s)
        cout<<str<<endl;

	return 0;
}

