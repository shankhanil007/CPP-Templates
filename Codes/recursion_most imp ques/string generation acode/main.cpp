#include <iostream>
#include <string>
using namespace std;

void find(char *input, char *output, int i,int j)
{
	if(input[i]=='\0')
	{
		output[j]='\0';
		cout<<output<<endl;
		return;
	}

		int digit = input[i]-'0';
		char ch = digit + 'A' -1;
		output[j]=ch;
		find(input, output, i+1,j+1);


	if(input[i+1]!='\0')
	{
		int secdigit = input[i+1]-'0';
		int no= digit*10+ secdigit;
		if( no<=26)
		{
			ch = no + 'A' -1;
			output[j]=ch;
			find(input, output, i+2,j+1);
		}
	}

	return;
}



int main() {

	char st[100];
	cin>>st;


	char output[100];

	find(st,output,0,0);

	return 0;
}
