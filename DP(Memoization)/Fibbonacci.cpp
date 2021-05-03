#include<bits/stdc++.h>
using namespace std;

int fibb(int n,int *arr)
{
    if(n<=1)
    {
        return 1;
    }

    if(arr[n]>0)
    {
        return arr[n];
    }

    arr[n]=fibb(n-1,arr)+fibb(n-2,arr);
    return fibb(n-1,arr)+fibb(n-2,arr);
}

int main()
{
    int n;
    cin>>n;
    int *arr=new int[n+1];
    for(int i=0;i<=n;i++)
    {
        arr[i]=0;
    }

    // int ans=fibb(n,arr);
    // cout<<ans<<endl;

    arr[0]=1;
    arr[1]=1;

    for(int i=2;i<=n;i++)
    {
        arr[i]=arr[i-1]+arr[i-2];
    }
    cout<<arr[n]<<endl;
}