#include <iostream>
#include <algorithm>
using namespace std;


/*int power(int a, int n)
{
    if(n==0)
        return 1;
    if(n&1==1)
        return a*power(a,(n-1)/2)*power(a,(n-1)/2);
    else
        return power(a,n/2)*power(a,n/2);
}



int main()
{
    int a,n; cin>>a>>n;
    cout<<power(a,n);
}
*/





//Bubble sort

/*
swap(int *a, int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

int sort(int *arr,int n,int i, int j)
{
    if(i==n-1)
        return 0;
    if(*(arr+j)>*(arr+j+1))
        swap(arr+j,arr+j+1);

    j++;
    if(j==(n-1-i))
    {
        i++;
        j=0;
    }
    sort(arr, n, i, j);

}





int main()
{
    int n; cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    sort(arr,n,0,0);

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
*/






//merge sort


/*merge(int *arr, int i,int mid,int j,int h)
{
    int temp[1000];int k=i; int s=i,e=h;

    while(i<=mid && j<=h)
    {
        if(arr[i]<arr[j])
        {
            temp[k++]=arr[i++];
        }
        else
        {
            temp[k++]=arr[j++];
        }
    }

    while(i<=mid)
    {
        temp[k++]=arr[i++];
    }

    while(j<=h)
    {
        temp[k++]=arr[j++];
    }

    for(;s<=e;s++)
    {
        arr[s]=temp[s];
    }

}

sort(int arr[],int l, int h)
{
    if(l==h)
        return 0;
    int mid=(l+h)/2;
    sort(arr,l,mid);
    sort(arr,mid+1,h);
    merge(arr,l,mid,mid+1,h);
}




int main()
{
    int n; cin>>n;
    int arr[n]; int count=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    sort(arr,0,n-1);

    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";

}*/



// inversion count

/*int merge(int *arr, int i,int mid,int j,int h)
{
    int temp[1000];int k=i; int s=i,e=h;        int x=0;

    while(i<=mid && j<=h)
    {
        if(arr[i]<=arr[j])
        {
            temp[k++]=arr[i++];
        }
        else
        {
            temp[k++]=arr[j++];
            x+=mid-i+1;
        }
    }

    while(i<=mid)
    {
        temp[k++]=arr[i++];
    }

    while(j<=h)
    {
        temp[k++]=arr[j++];
    }

    for(;s<=e;s++)
    {
        arr[s]=temp[s];
    }

    return x;
}


int sort(int arr[],int l, int h)
{
    if(l==h)
        return 0;
    int mid=(l+h)/2;
    int x=sort(arr,l,mid);
    int y=sort(arr,mid+1,h);
    int z=merge(arr,l,mid,mid+1,h);

    return x+y+z;
}



int main()
{
    int n; cin>>n;
    int arr[n]; int count=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    cout<<sort(arr,0,n-1);

    return 0;
}
*/



//Quick sort

int partion(int *arr,int l,int h)
{
    int key=arr[h];
    int i=l-1;
    for(int j=l;j<=h-1;j++)
    {
        if(arr[j]<=key)
        {
            swap(arr[i+1],arr[j]);
            i++;
        }
    }

    swap(arr[i+1],arr[h]);
    return i+1;
}


void sort(int *arr, int l, int h)
{
    if(l>=h)
        return ;

    int p=partion(arr,l,h);

    sort(arr,l,p-1);
    sort(arr,p+1,h);
}


int main()
{
    int n; cin>>n;
    int arr[n]; int count=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    sort(arr,0,n-1);

    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";

    return 0;
}
