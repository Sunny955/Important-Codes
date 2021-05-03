#include <bits/stdc++.h>
using namespace std;

/* Recurrsion and Backtracikng */

long denom(int n,int *freq,int *fact)
{
    long mult=1;
    for(int i=0;i<n;i++)
    {
        if(freq[i]>0)
        {
            mult*=fact[freq[i]];
        }
    }
    return mult;
}

int num(int *input,int *fact,int *freq,int n)
{
    if(n==0 || n==1)
    {
        return 0;
    }

    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(input[i]>input[0])
        {
            ans+=((fact[n-1]*freq[input[i]])/denom(10,freq,fact));
        }
    }
    freq[input[0]]--;
    ans+=num(input+1,fact,freq,n-1);
    return ans;
}

int main()
{
    int n;
    cin>>n;
    int *input=new int[n];
    int *fact=new int[n+1];
    fact[0]=1;
    int freq[10]={};
    for(int i=0;i<n;i++)
    {
        cin>>input[i];
        fact[i+1]=(i+1)*fact[i];
        freq[input[i]]++;
    }

    cout<<num(input,fact,freq,n);
}