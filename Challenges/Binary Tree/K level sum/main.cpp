#include<bits/stdc++.h>
#include<queue>
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


class node{;
    public:
        int data;
        node* left;
        node* right;

    node(int d)
    {
        data = d;
        left=NULL;
        right=NULL;
    }

};


node* buildTree(int d)
{
    if(d>0)
    {
        int no; cin>>no;
        node* root = new node(no);

        int dig; cin>>dig;
        if(dig==1)
        {
            root->left = buildTree(1);
        }
        if(dig==2)
        {
            root->left = buildTree(2);
            root->right = buildTree(2);
        }

        return root;
    }

    else
        return NULL;

}

void bfs(node* root)
{
    queue <node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        node* top = q.front();
        if(top == NULL)
        {
            cout<<endl;
            q.pop();
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout<<top->data<<" ";
            q.pop();

            if(top->left)
                q.push(top->left);
            if(top->right)
                q.push(top->right);
        }
    }
}

int sum=0;

void KSumLevel(node* root, int k)
{
    if(root == NULL)
        return;

    if(k == 0)
    {
        sum+=root->data;
        return;
    }

    KSumLevel(root->left,   k-1);
    KSumLevel(root->right, k-1);

    return;
}




int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    node* root = buildTree(1);

    int k; cin>>k;

    KSumLevel(root,k);

    cout<<sum;

    return 0;
}


