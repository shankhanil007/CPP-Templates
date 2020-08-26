#include<bits/stdc++.h>
#include<queue>
#include<vector>
#include<string>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define pb push_back
#define deb(x) cout<<#x<<" : "<<x<<"\n";
#define debug(x,y) cout<<#x<<" : "<<x<<"\t"<<#y<<" : "<<y<<"\n";
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define setp(n) cout << fixed << setprecision(n)
#define mset(x,y) memset(x,y,sizeof(x))
#define mp(x,y) make_pair(x,y)
#define checkbit(x,i) (x&(1ll<<i))?1:0
#define setbit(x,i) x|(1ll<<i)
#define compbit(x,i) x^(1ll<<i)
#define ff first
#define ss second
#define mod 1000000007
#define N 100010


class node{
    public:
        int data;
        node* left;
        node* right;

    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }

};


node *buildTree(string s)
{
    if (s == "true")
    {
        int d;
        cin >> d;
        node *root = new node(d);
        string l;
        cin >> l;
        if (l == "true")
        {
            root->left = buildTree(l);
        }
        string r;
        cin >> r;
        if (r == "true")
        {
            root->right = buildTree(r);
        }
        return root;
    }
    return NULL;
}



void levelOrder(node* root)
{
    queue <pair <node*, int>> q;
    vector <int> v;
    q.push(make_pair(root,1));

    while(!q.empty())
    {
        pair <node*, int> p = q.front();

        if(p.second%2==1)
        {

                while(!v.empty())
                {
                    cout<<v.back()<<" ";
                    v.pop_back();
                }


            cout<<p.first->data<<" ";
        }

        else
        {
            v.push_back(p.first->data);
        }


        q.pop();

        if(p.first->left)
            q.push(make_pair(p.first->left,p.second+1));
        if(p.first->right)
            q.push(make_pair(p.first->right,p.second+1));

        if(q.empty() && !v.empty())
        {
            while(!v.empty())
                {
                    cout<<v.back()<<" ";
                    v.pop_back();
                }
        }
    }
    return ;
}




int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    node* root = buildTree("true");

    levelOrder(root);

    return 0;
}
