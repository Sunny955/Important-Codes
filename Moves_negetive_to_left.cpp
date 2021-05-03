
#include <bits/stdc++.h>
using namespace std;


void shift(int *arr,int n)
{
    int i,j;
    i=0;
    j=n-1;
    while(j>i)
    {
        if(arr[i]<0 && arr[j]<0)
        {
            i++;
        }
        
        if(arr[i]>0 && arr[j]<0)
        {
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
        
        if(arr[i]<0 && arr[j]>0)
        {
            i++;
            j--;
        }
        
        if(arr[i]>0 && arr[j]>0)
        {
            j--;
        }
    }
}

int main() {
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
	    cin>>arr[i];
	}
	shift(arr,n);
	for(int i=0;i<n;i++)
	{
	    cout<<arr[i]<<" ";
	}
	return 0;
}