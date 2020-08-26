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


node* buildTree(int* pre, int* in,int s, int e)
{
    static int i=0;

    if(s>e)
    {
        return NULL;
    }

    node* root = new node(pre[i]);

    int index=-1;
    for(int j=s;s<=e;j++)
    {
        if(pre[i]==in[j])
        {
            index=j;
            break;
        }
    }

    i++;
    root->left = buildTree(pre,in,s, index-1);
    root->right = buildTree(pre, in, index+1, e);

    return root;
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


void preorder(node* root)
{
    if(root==NULL)
    {
        return;
    }

    if(root->left!=NULL)
        cout<<root->left->data<<" => ";
    else
        cout<<"END => ";
    cout<<root->data<<" ";
    if(root->right!=NULL)
        cout<<" <= "<<root->right->data<<endl;
    else
        cout<<"<= END"<<endl;

    preorder(root->left);
    preorder(root->right);

}



int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int n,m; cin>>n;
    int pre[n];
    for(int i=0;i<n;i++)
        cin>>pre[i];
    cin>>m;
    int in[m];
    for(int j=0;j<m;j++)
        cin>>in[j];

    node* root = buildTree(pre,in,0,n-1);

    preorder(root);

    return 0;
}
