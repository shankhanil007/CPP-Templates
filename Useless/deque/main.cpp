#include <iostream>
#include <string>
#include <deque>
#include  <unordered_map>
using namespace std;

int main()
{
    string st;  cin>>st;
    int ans=0,len=0;
    deque <char> d; deque <char> c;
    unordered_map <char, int> mp;

    for(int i=0;i<st.length();i++)
    {
        int flag=0;
        char ch=st[i];
        //cout<<ch<<endl;
        d.push_back(ch);
        mp[ch]++;

        len=d.size();

        c=d;

        while(!d.empty())
        {
            cout<<d.front()<<endl;
            d.pop_back();
        }


        while(!c.empty())
        {
            if(mp[c.front()]>1)
            {
                while(!d.empty())
                {
                    d.pop_back();
                }
                flag=1;
                break;
            }
            c.pop_back();
        }

        if(flag==0)
        {
            if(len>ans)
                ans=len;
        }

        //cout<<flag<<endl;

    }



    return 0;
}
